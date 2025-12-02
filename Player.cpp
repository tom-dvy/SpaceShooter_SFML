#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

Player::Player()
{
    score = 0;
    speed = 300.0f;

    shape.setSize(sf::Vector2f(50.f, 30.f));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getSize() / 2.0f);
    shape.setPosition(500.f, 700.f);

    SpaceShip::GetStats();

    //std::cout << "Player::Player this=" << this << " weapon=" << weapon << std::endl;
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
        Weapon* w = GetWeapon();
        if (w)
        {
            w->Shoot(shape.getPosition(), sf::Vector2f(0.0f, -1.0f));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        Weapon* w = GetWeapon();
        if (w)
        {
            w->Reload();
        }
    }
    
}

void Player::Display(sf::RenderWindow &window)
{
    window.draw(shape);
}

const sf::FloatRect Player::GetBounds() const
{
    return shape.getGlobalBounds();
}

void Player::Respawn()
{
    life = 3;
    shape.setPosition(500.f, 700.f);
    std::cout << "Player a respawn. Vies : " << life << std::endl;
}