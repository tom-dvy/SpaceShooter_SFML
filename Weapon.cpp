#include "Weapon.h"
#include <iostream>

Weapon::Weapon(int dmg, int mun, float shootCooldown)
    : damage(dmg), munition(mun), shootCooldown(shootCooldown)
{
}

void Weapon::Shoot(const sf::Vector2f& position, const sf::Vector2f& direction)
{
    float elapsed = shootClock.getElapsedTime().asSeconds();
    if (elapsed < shootCooldown)
        return;

    if (munition > 0)
    {
        projectiles.emplace_back(position, direction);
        munition--;
        shootClock.restart();
        std::cout << "Tir du joueur" << std::endl;
    }
}

void Weapon::UpdateProjectiles(float dt, sf::RenderWindow& window)
{
    for (auto it = projectiles.begin(); it != projectiles.end(); )
    {
        it->Update(dt);
        if (it->IsOffScreen(window))
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
    munition = 10;
}

void Weapon::DrawProjectiles(sf::RenderWindow& window) const
{
    for (const auto& proj : projectiles)
        proj.Draw(window);
}
