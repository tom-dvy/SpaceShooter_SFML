#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Enemy::Enemy()
{
}

void Enemy::AiMove()
{
}

void Enemy::AiShoot()
{
}

void Enemy::Display(sf::RenderWindow &window)
{
    spawner.SpawnEnemies(3, window);
}