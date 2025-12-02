#include "Weapon.h"
#include <iostream>

Weapon::Weapon(int dmg, int mun, float shootCooldown)
    : damage(dmg), munition(mun), shootCooldown(shootCooldown)
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
    if (munition <= 0)
    {
        munition = 10;
        std::cout << "Rechargement de "<< munition <<" munitions" << std::endl;
    }
    else
    {
        std::cout << "Vous avez encore "<< munition <<" munitions" << std::endl;
    }
}

void Weapon::DrawProjectiles(sf::RenderWindow &window) const
{
    for (const auto &proj : projectiles)
        proj.Draw(window);
}
