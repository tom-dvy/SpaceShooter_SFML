#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

Game::Game()
{
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
        
        // Mettre à jour la position des projectiles
        player.weapon->UpdateProjectiles(deltaTime, window);

        // Affichage de l'écran
        window.clear(sf::Color::Black);

        // Dessiner projectiles et joueur
        player.weapon->DrawProjectiles(window);
        player.Display(window);
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