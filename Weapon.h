#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include "Projectiles.h"
#include "Gun.h"

class Weapon : public Gun
{
public:
    Weapon(int damage = 1, int munition = 10, float shootCooldown = 0.5f);

    void Shoot(const sf::Vector2f& position, const sf::Vector2f& direction);
    void UpdateProjectiles(float dt, sf::RenderWindow& window);
    void Reload();
    void DrawProjectiles(sf::RenderWindow& window) const;
    std::vector<Projectile>& GetProjectiles() { return projectiles; };

private:
    int damage;
    int munition;
    std::vector<Projectile> projectiles;
    sf::Clock shootClock;
    float shootCooldown;
};

#endif // WEAPON_H
