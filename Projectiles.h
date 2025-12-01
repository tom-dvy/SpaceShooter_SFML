#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

class Projectile
{
public:
    Projectile(const sf::Vector2f& pos, const sf::Vector2f& dir, float speed = 400.f);

    void Update(float dt);
    const sf::RectangleShape& GetShape() const { return shape; }
    void Draw(sf::RenderWindow& window) const;
    bool IsOffScreen(const sf::RenderWindow& window) const;

    bool toDelete = false;

private:
    sf::RectangleShape shape;
    sf::Vector2f direction;
    float speed;
};

#endif // PROJECTILE_H