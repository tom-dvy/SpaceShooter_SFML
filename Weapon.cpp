#include "Weapon.h"
#include <iostream>

Weapon::Weapon(float dmg, int mun, float shootCooldown)
    : damage(dmg), munition(mun), maxMunition(mun), shootCooldown(shootCooldown)
{
}

void Weapon::Shoot(const sf::Vector2f &position, const sf::Vector2f &direction)
{
    float elapsed = shootClock.getElapsedTime().asSeconds();
    if (elapsed < shootCooldown)
        return;

    if (munition > 0)
    {
        projectiles.emplace_back(position, direction);
        munition--;
        shootClock.restart();
        std::cout << "Piuuu Piuuu" << std::endl;
    }
}

void Weapon::UpdateProjectiles(float dt, sf::RenderWindow& window)
{
    for (auto it = projectiles.begin(); it != projectiles.end(); )
    {
        it->Update(dt);

        if (it->IsOffScreen(window) || it->toDelete)
        {
            it = projectiles.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Weapon::Reload()
{
    float elapsed = shootClock.getElapsedTime().asSeconds();
    if (elapsed < shootCooldown)
        return;

    shootClock.restart();
    
    munition = maxMunition;
    std::cout << "Rechargement de "<< munition <<" munitions" << std::endl;
}

void Weapon::DrawProjectiles(sf::RenderWindow &window) const
{
    for (const auto &proj : projectiles)
        proj.Draw(window);
}
