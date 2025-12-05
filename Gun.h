#ifndef GUN_H
#define GUN_H

#include "Weapon.h"

class Gun : public Weapon
{
public:
    Gun();
    ~Gun() = default;
    
    void Shoot(const sf::Vector2f& position, const sf::Vector2f& direction) override;
};

#endif // GUN_H
