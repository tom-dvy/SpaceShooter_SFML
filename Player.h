#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include <windows.h>
#include <iostream>
#include <vector>

class Player : public SpaceShip
{
public:
    Player();
    void SetScore(int score);
    void GetMoveInput(const sf::RenderWindow& window);
    void GetShootInput(sf::RenderWindow& window);
    void Display(sf::RenderWindow& window);
private:
    int score;
    sf::RectangleShape shape;
    float speed;
};

#endif // PLAYER_H