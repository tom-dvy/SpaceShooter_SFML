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
    void Display(sf::RenderWindow& window);
private:
    int score;
    sf::RectangleShape shape;
    float speed;
};
#endif // PLAYER_H