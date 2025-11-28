#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include <iostream>

class Enemy : public SpaceShip
{
public:
    Enemy();
    void AiMove();
    void AiShoot();
};

#endif // ENEMY_H