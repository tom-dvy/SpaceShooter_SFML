#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include <iostream>

class Player : public SpaceShip
{
public:
    Player();
    ~Player() override = default;

    void SetScore(int score);
    void GetMoveInput(const sf::RenderWindow& window);
    void GetShootInput();
    const sf::FloatRect GetBounds() const;
    void Display(sf::RenderWindow& window);
    void Respawn();
    sf::RectangleShape& GetShape() { return shape; }
private:
    int score;
    sf::RectangleShape shape;
    float speed;
};
#endif // PLAYER_H