#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

Game::Game()
{
    for (int i = 0; i < nbEnemies; i++)
    {
        enemies.push_back(Enemy());
    }
    playerLives = 3;
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
        HandleEvents(window);

        bool isGameOver = false;
        Update(player, deltaTime, window, isGameOver);

        Render(window, player, isGameOver);
    }
}

void Game::HandleEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::Update(Player& player, float deltaTime, sf::RenderWindow& window, bool &isGameOver)
{
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
        if (enemy.GetWeapon())
            enemy.GetWeapon()->UpdateProjectiles(deltaTime, window);
    }

    // Gestion des collisions et dégats (projectiles joueur -> ennemis)
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

    // Gestion des dégats et collisions sur le joueur (projectiles ennemis -> joueur)
    for (auto &enemy : enemies)
    {
        Weapon* ew = enemy.GetWeapon();
        if (!ew) continue;
        for (auto &eproj : ew->GetProjectiles())
        {
            if (eproj.GetShape().getGlobalBounds().intersects(player.GetBounds()))
            {
                player.TakeDamage(1);
                eproj.toDelete = true;
            }
        }
    }

    // Mort et Respawn Joueur
    if (player.IsDead())
    {
        playerLives--;
        if (playerLives == 0)
        {
            std::cout << "Game Over" << std::endl;
            isGameOver = true;
        }
        else
        {
            std::cout << "Player died. Respawning... Remaining lives: " << playerLives << std::endl;
            player.Respawn();
        }
    }

    // Supprimer les projectiles marqués (player)
    if (player.GetWeapon())
        player.GetWeapon()->UpdateProjectiles(deltaTime, window);

    // Mort d'un ennemi
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
                       [](const Enemy &e)
                       { return e.IsDead(); }),
        enemies.end());
}

void Game::Render(sf::RenderWindow& window, Player& player, bool isGameOver)
{
    window.clear(sf::Color::Black);

    if (!isGameOver)
    {
        // Dessiner projectiles joueur
        if (player.GetWeapon())
            player.GetWeapon()->DrawProjectiles(window);
        // Dessiner projectiles ennemis
        for (auto &enemy : enemies)
        {
            if (enemy.GetWeapon())
                enemy.GetWeapon()->DrawProjectiles(window);
        }

        player.Display(window);

        for (auto &enemy : enemies)
        {
            enemy.Display(window);
        }
    }

    window.display();
}

void Game::NextLevel()
{
}

void Game::IsGameOver()
{
}