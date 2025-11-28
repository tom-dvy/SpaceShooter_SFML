#include "Weapon.h"

Weapon::Weapon(int dmg, int mun) : damage(dmg), munition(mun) {}

void Weapon::Shoot(const sf::Vector2f& position, const sf::Vector2f& direction)
{
    if (munition > 0)
    {
        projectiles.emplace_back(position, direction);
        munition--;
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
    
}

void Weapon::DrawProjectiles(sf::RenderWindow& window) const
{
    for (const auto& proj : projectiles)
        proj.Draw(window);
}