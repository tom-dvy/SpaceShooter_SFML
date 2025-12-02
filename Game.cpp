#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

Game::Game()
{
    for (int i = 0; i < nbEnemies; i++)
    {
        enemies.push_back(Enemy());
    }
}

Game::~Game()
{
}

void Game::Start()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Space Shooter");
    window.setFramerateLimit(60);

    Player player;
    float deltaTime = 1.0f / 60.0f;

    player.SetWeapon(new Weapon(1, 10, 0.5f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Mouvement du joueur
        player.GetMoveInput(window);

        // Tirs du joueur
        player.GetShootInput();

        // Mettre à jour la position des projectiles du joueur
        if (player.GetWeapon())
            player.GetWeapon()->UpdateProjectiles(deltaTime, window);

        for (auto &enemy : enemies)
        {
            enemy.AiMove(window);
            enemy.AiShoot();
        }

        // Gestion des collisions et dégats
        Weapon* pw = player.GetWeapon();
        if (pw)
        {
            for (auto &projectile : pw->GetProjectiles())
            {
                for (auto &enemy : enemies)
                {
                    if (projectile.GetShape().getGlobalBounds().intersects(enemy.shape.getGlobalBounds()))
                    {
                        enemy.TakeDamage(1);
                        projectile.toDelete = true;
                    }
                }
            }
        }
        

        // Supprimer les projectiles marqués
        if (player.GetWeapon())
            player.GetWeapon()->UpdateProjectiles(deltaTime, window);

        // Mort d'un ennemi
        enemies.erase(
            std::remove_if(enemies.begin(), enemies.end(),
                           [](const Enemy &e)
                           { return e.IsDead(); }),
            enemies.end());

        // Affichage de l'écran
        window.clear(sf::Color::Black);

        // Dessiner projectiles ennemis et joueur
        if (player.GetWeapon())
            player.GetWeapon()->DrawProjectiles(window);
        player.Display(window);

        for (auto &enemy : enemies)
        {
            enemy.Display(window);
        }

        window.display();
    }
}

void Game::NextLevel()
{
}

void Game::Respawn()
{
}

void Game::IsGameOver()
{
}