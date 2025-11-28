#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <windows.h>

Game::Game()
{
}

void Game::Start()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Space Shooter");
    window.setFramerateLimit(60);

    Player player;

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
        player.GetShootInput(window);

        // Affichage de l'écran
        window.clear(sf::Color::Black);
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