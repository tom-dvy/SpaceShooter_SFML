#include "Gun.h"
#include <iostream>

Gun::Gun() : Weapon(3, 10, 0.5f)
{
    // Gun: 3 dégâts, 10 munitions, cadence normale (0.5s)
}

void Gun::Shoot(const sf::Vector2f& position, const sf::Vector2f& direction)
{
    Weapon::Shoot(position, direction);
}