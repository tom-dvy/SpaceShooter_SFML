#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include <iostream>

class SpaceShip
{
public:
    SpaceShip();
    virtual ~SpaceShip();
    void GetStats();
    void TakeDamage(int damage, sf::RectangleShape& shape);
    void Move(const sf::Vector2f& direction, sf::RectangleShape& shape, const sf::RenderWindow& window);
    bool IsDead() const;

    Weapon* weapon;

protected:
    int life;
    int speed;
    sf::Vector2f position;
};

#endif // SPACESHIP_H