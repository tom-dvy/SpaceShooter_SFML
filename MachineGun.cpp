#include "MachineGun.h"
#include <iostream>

MachineGun::MachineGun() : Weapon(1, 50, 0.1f)
{
    // Mitrailleuse: 1 dégâts, 50 munitions, cadence rapide (0.1s)
}

void MachineGun::Shoot(const sf::Vector2f& position, const sf::Vector2f& direction)
{
    Weapon::Shoot(position, direction);
}
