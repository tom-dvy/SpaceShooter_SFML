#include "Weapon.h"
#include <SFML/Graphics.hpp>

Weapon::Weapon() : damage(1), munition(10)
{
    name[0] = '\0';
}

void Weapon::Shoot(sf::Vector2f position, sf::Vector2f direction, sf::RenderWindow& window)
{
    if (munition > 0)
    {
        Projectiles projectile;
        projectile.SpawnProjectile(position, window);
        
        munition--;
    }
    if (munition = 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        Reload();
    }
    
}

void Weapon::Reload()
{
    munition = 10;
}
