#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include "EnemySpawner.h"
#include <iostream>

class Enemy : public SpaceShip
{
public:
    Enemy();
    void AiMove();
    void AiShoot();
    void Display(sf::RenderWindow &window);

private:
EnemySpawner spawner;
};

#endif // ENEMY_H