#include "EnemySpawner.h"
#include <SFML/Graphics.hpp>
#include <iostream>

EnemySpawner::EnemySpawner()
{
    positions = sf::Vector2f(50.0f, 30.0f);
   
    enemy.setSize(positions);
    enemy.setFillColor(sf::Color::Red);
    enemy.setOrigin(enemy.getSize() / 2.f);
    enemy.setPosition(500.f, 300.f);}

void EnemySpawner::SpawnEnemies(int count, sf::RenderWindow &window)
{
    window.draw(enemy);
}