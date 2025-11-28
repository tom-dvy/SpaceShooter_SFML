#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include <windows.h>
#include <iostream>
#include <vector>

class Enemy : public SpaceShip
{
public:
    Enemy();
    void AiMove();
    void AiShoot();

private:
};

#endif // ENEMY_H