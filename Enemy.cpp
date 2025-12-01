#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Enemy::Enemy()
{
    shape.setSize(sf::Vector2f(50.0f, 30.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(shape.getSize() / 2.f);
    shape.setPosition(500.f, 300.f);
}

void Enemy::AiMove()
{
    //shape.move(0, 0.5f);
}

void Enemy::AiShoot()
{
}

void Enemy::Display(sf::RenderWindow &window)
{
    window.draw(shape);
}