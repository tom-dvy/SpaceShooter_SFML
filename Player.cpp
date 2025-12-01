#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player()
{
    score = 0;
    speed = 300.0f;

    shape.setSize(sf::Vector2f(50.f, 30.f));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getSize() / 2.f);
    shape.setPosition(500.f, 700.f);

    SpaceShip::GetStats();

    weapon = new Weapon(1, 10, 0.5f);
}

void Player::SetScore(int scorePlayer)
{
    // Gestion du score du joueur
    score = scorePlayer;
    std::cout << "Score : " << score << std::endl;
}

void Player::GetMoveInput(const sf::RenderWindow &window)
{
    const float direction = 1.0f / 60.0f;
    sf::Vector2f movement(0.0f, 0.0f);

    // Déplacement à gauche
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        movement.x -= speed * direction;
    }

    // Déplacement à droite
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += speed * direction;
    }

    // Déplacement en haut
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        movement.y -= speed * direction;
    }

    // Déplacement en bas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += speed * direction;
    }

    Move(movement, shape, window);
}

void Player::GetShootInput()
{
    // Gestion des tirs du joueur
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (weapon)
        {            
            weapon->Shoot(shape.getPosition(), sf::Vector2f(0.0f, -1.0f));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        if (weapon)
        {
            weapon->Reload();
        }
        
    }
    
}

void Player::Display(sf::RenderWindow &window)
{
    window.draw(shape);
}