#ifndef PROJECTILES_H
#define PROJECTILES_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "SpaceShip.h"
#include <windows.h>
#include <iostream>
#include <vector>

class Projectiles
{
public:
    Projectiles();
    void SpawnProjectile(sf::Vector2f position, sf::RenderWindow& window);
    sf::RectangleShape projectileShape;

private:
    int speed;
    bool fromPlayer;
    int damage;
};

#endif // PROJECTILES_H