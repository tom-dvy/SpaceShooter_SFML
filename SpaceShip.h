#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include <iostream>
#include <memory>

class SpaceShip
{
public:
    SpaceShip();
    virtual ~SpaceShip() = default;
    void GetStats();
    void TakeDamage(float damage, sf::RectangleShape& shape);
    void Move(const sf::Vector2f& direction, sf::RectangleShape& shape, const sf::RenderWindow& window);
    bool IsDead() const;
    void SetWeapon(Weapon* w) { weapon.reset(w); }
    Weapon* GetWeapon() const { return weapon.get(); }

    SpaceShip(SpaceShip&&) noexcept = default;
    SpaceShip& operator=(SpaceShip&&) noexcept = default;
protected:
    std::unique_ptr<Weapon> weapon;
    int life;
    int speed;
    sf::Vector2f position;
};

#endif // SPACESHIP_H