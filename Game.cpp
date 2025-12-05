#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

Game::Game(int numberOfEnemies) : nbEnemies(numberOfEnemies)
{
    // Créer les ennemis
    for (int i = 0; i < nbEnemies; i++)
    {
        enemies.push_back(Enemy());
    }
    playerLives = 3;
    score = 0;
    
    // Police d'écriture
    if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
    {
        std::cerr << "Erreur: impossible de charger la police" << std::endl;
    }
}

Game::~Game()
{
}

void Game::Start()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Space Shooter"); // Titre et taille de la fenêtre de jeu
    window.setFramerateLimit(60); // FrameRate

    Player player;

    float deltaTime = 1.0f / 60.0f;

    player.SetWeapon(new Weapon(1, 10, 0.5f)); // Donne une weapon a Player

    bool isGameOver = false;

    while (window.isOpen())
    {
        HandleEvents(window);

        // Tant que le joueur n'est pas mort, le jeu tourne normalement
        if (!isGameOver)
        {
            Update(player, deltaTime, window, isGameOver);
        }
        else
        {
            // Quand le jeu est terminé, vérifier si l'utilisateur appuie sur Enter
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                // Réinitialiser le jeu
                isGameOver = false;
                playerLives = 3;
                score = 0;
                player.Respawn();
                enemies.clear();
                for (int i = 0; i < nbEnemies; i++)
                {
                    enemies.push_back(Enemy());
                }
            }
        }

        Render(window, player, isGameOver); // Affiche le jeu
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

    // Gestion du changement d'arme
    player.HandleWeaponSwitch();

    // Tirs du joueur
    player.GetShootInput();

    // Mettre à jour la position des projectiles du joueur
    if (player.GetWeapon())
    {
        player.GetWeapon()->UpdateProjectiles(deltaTime, window);
    }

    // Mouvements et tirs ennemis
    for (auto &enemy : enemies)
    {
        enemy.AiMove(window);
        enemy.AiShoot();
        if (enemy.GetWeapon())
        {
            enemy.GetWeapon()->UpdateProjectiles(deltaTime, window);
        }
    }

    // Gestion des collisions et dégats (projectiles joueur => ennemis)
    Weapon* playerWeapon = player.GetWeapon(); // Récupère l'arme du joueur
    if (playerWeapon)
    {
        for (auto &projectile : playerWeapon->GetProjectiles())
        {
            for (auto &enemy : enemies)
            {
                if (projectile.GetShape().getGlobalBounds().intersects(enemy.shape.getGlobalBounds()))
                {
                    enemy.TakeDamage(playerWeapon->GetDamage(), enemy.shape);
                    projectile.toDelete = true;
                }
            }
        }
    }

    // Gestion des dégats et collisions sur le joueur (projectiles ennemis -> joueur)
    for (auto &enemy : enemies)
    {
        Weapon* enemyWeapon = enemy.GetWeapon();
        if (!enemyWeapon) continue;
        for (auto &eproj : enemyWeapon->GetProjectiles())
        {
            if (eproj.GetShape().getGlobalBounds().intersects(player.GetBounds()))
            {
                player.TakeDamage(1, player.GetShape());
                eproj.toDelete = true;
            }
        }
    }

    // Mort et Respawn Joueur
    if (player.IsDead())
    {
        playerLives--;
        // Si le joueur n'a plus de vie => Game Over
        if (playerLives == 0)
        {
            std::cout << "Game Over" << std::endl;
            isGameOver = true;
        }
        else
        {
            std::cout << "Vie restante : " << playerLives << std::endl;
            player.Respawn();
        }
    }

    // Supprimer les projectiles du joueur
    if (player.GetWeapon())
        player.GetWeapon()->UpdateProjectiles(deltaTime, window);

    // Mort et suppression d'un ennemi
    for (const auto &enemy : enemies)
    {
        if (enemy.IsDead())
        {
            score++;
        }
    }
    
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),[](const Enemy &e){ return e.IsDead(); }), enemies.end());
}

void Game::Render(sf::RenderWindow& window, Player& player, bool isGameOver)
{
    window.clear(sf::Color::Black); // BackGround du jeu

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

        // Affichage du joueur
        player.Display(window);

        // Affichage des ennemis
        for (auto &enemy : enemies)
        {
            enemy.Display(window);
        }

        player.SetScore(score, font, window);
    }
    else
    {
        // Afficher "Game Over" au centre de l'écran
        sf::Text gameOverText("GAME OVER", font, 80);
        gameOverText.setFillColor(sf::Color::Red);
        
        // Centrer le texte
        sf::FloatRect textBounds = gameOverText.getLocalBounds();
        gameOverText.setPosition(
            (window.getSize().x - textBounds.width) / 2.0f,
            (window.getSize().y - textBounds.height) / 2.0f
        );
        
        window.draw(gameOverText);
        
        // Afficher le message "Appuyez sur Enter"
        sf::Text pressEnterText("Appuyer sur ENTER pour relancer", font, 30);
        pressEnterText.setFillColor(sf::Color::White);
        sf::FloatRect enterTextBounds = pressEnterText.getLocalBounds();
        pressEnterText.setPosition(
            (window.getSize().x - enterTextBounds.width) / 2.0f,
            (window.getSize().y - enterTextBounds.height) / 2.0f + 120.0f
        );
        
        window.draw(pressEnterText);
    }

    window.display();
}

void Game::NextLevel()
{
}