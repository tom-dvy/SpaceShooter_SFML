#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include "Projectiles.h"

class Weapon
{
public:
    Weapon(float damage = 1, int munition = 10, float shootCooldown = 0.5f);
    virtual ~Weapon() = default;

    virtual void Shoot(const sf::Vector2f& position, const sf::Vector2f& direction);
    void UpdateProjectiles(float dt, sf::RenderWindow& window);
    void Reload();
    void DrawProjectiles(sf::RenderWindow& window) const;
    std::vector<Projectile>& GetProjectiles() { return projectiles; };
    int GetDamage() const { return (int)damage; }
    int GetMunition() const { return munition; }
    float GetShootCooldown() const { return shootCooldown; }
    int GetMaxMunition() const { return maxMunition; }

protected:
    float damage;
    int munition;
    int maxMunition;
    std::vector<Projectile> projectiles;
    sf::Clock shootClock;
    float shootCooldown;
};

#endif // WEAPON_H
