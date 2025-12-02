#ifndef GUN_H
#define GUN_H

#include "Weapon.h"

class Gun
{
public:
    Gun();
    ~Gun();
    void Shoot(const sf::Vector2f& position, const sf::Vector2f& direction);
};

#endif // GUN_H
