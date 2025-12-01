#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Enemy::Enemy()
{
    speed = 150.0f;

    shape.setSize(sf::Vector2f(50.0f, 30.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(shape.getSize() / 2.f);
    shape.setPosition(500.f, 300.f);
}

void Enemy::AiMove(sf::RenderWindow& window)
{
    sf::Vector2f movement(0.0f, 0.0f);
    
    movement.x += speed * direction * (1.0f / 60.0f);

    Move(movement, shape, window);

    // Double vérification des limites, Voir plus tard si on peut faire plus simple
    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f half = shape.getSize() / 2.f;
    sf::Vector2u win = window.getSize();

    if (pos.x <= half.x)
    {
        direction = 1.0f;
    }
    else if (pos.x >= static_cast<float>(win.x) - half.x)
    {
        direction = -1.0f;
    }
}

void Enemy::AiShoot()
{
}

void Enemy::Display(sf::RenderWindow &window)
{
    window.draw(shape);
}