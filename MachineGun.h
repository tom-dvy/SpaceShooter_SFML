#ifndef MACHINEGUN_H
#define MACHINEGUN_H

#include "Weapon.h"

class MachineGun : public Weapon
{
public:
    MachineGun();
    ~MachineGun() override = default;
    
    void Shoot(const sf::Vector2f& position, const sf::Vector2f& direction) override;

private:
};

#endif // MACHINEGUN_H
