#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include <windows.h>
#include <iostream>
#include <vector>

class SpaceShip :
{
public:
    SpaceShip();
    void GetStats();
    void TakeDamage(int damage);
    void Move(sf::Vector2f direction, sf::RectangleShape& shape, const sf::RenderWindow& window);
    void IsDead();

private:
    int life;
    int speed;
    sf::Vector2f position;
    Weapon* weapon;
};

#endif // SPACESHIP_H