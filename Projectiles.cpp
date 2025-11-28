#include "Projectiles.h"

Projectile::Projectile(const sf::Vector2f& pos, const sf::Vector2f& dir, float speed) : direction(dir), speed(speed)
{
    shape.setSize({10.f, 30.f});
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(shape.getSize() / 2.0f);
    shape.setPosition(pos);
}

void Projectile::Update(float dt)
{
    shape.move(direction * speed * dt);
}

void Projectile::Draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}

bool Projectile::IsOffScreen(const sf::RenderWindow& window) const
{
    sf::Vector2f pos = shape.getPosition();
    return pos.y < 0 || pos.y > window.getSize().y || pos.x < 0 || pos.x > window.getSize().x;
}