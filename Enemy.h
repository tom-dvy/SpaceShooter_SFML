#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"

class Enemy : public SpaceShip
{
public:
    Enemy();
    void AiMove();
    void AiShoot();
    void Display(sf::RenderWindow &window);

    sf::RectangleShape shape;
private:
};

#endif // ENEMY_H