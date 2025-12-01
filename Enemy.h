#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"

class Enemy : public SpaceShip
{
public:
    Enemy();
    void AiMove(sf::RenderWindow &window);
    void AiShoot();
    void Display(sf::RenderWindow &window);
    sf::RectangleShape shape;
    float direction = 1.0f;
private:
    float speed;
};

#endif // ENEMY_H