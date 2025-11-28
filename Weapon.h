#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Projectiles.h"
#include <iostream>
#include <vector>

class Weapon : public Projectiles
{
public:
    Weapon();
    void Shoot(sf::Vector2f position, sf::Vector2f direction, sf::RenderWindow& window);
    void Reload();

private:
    int damage;
    int munition;
    char name[50];
};

#endif // WEAPON_H