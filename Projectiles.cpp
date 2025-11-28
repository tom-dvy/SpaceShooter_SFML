#include <SFML/Graphics.hpp>
#include "Projectiles.h"
#include <iostream>

Projectiles::Projectiles() : speed(400), fromPlayer(true), damage(1)
{
}

void Projectiles::SpawnProjectile(sf::Vector2f position, sf::RenderWindow& window)
{
    projectileShape.setSize(sf::Vector2f(10.0f, 30.0f));
    projectileShape.setFillColor(sf::Color::Blue);
    projectileShape.setOrigin(projectileShape.getSize() / 2.0f);
    projectileShape.setPosition(position);

    window.draw(projectileShape);
}