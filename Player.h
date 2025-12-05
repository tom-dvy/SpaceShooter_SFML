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

    void SetScore(int score, sf::Font font, sf::RenderWindow& window);
    void GetMoveInput(const sf::RenderWindow& window);
    void GetShootInput();
    void HandleWeaponSwitch();
    const sf::FloatRect GetBounds() const;
    void Display(sf::RenderWindow& window);
    void Respawn();
    sf::RectangleShape& GetShape() { return shape; }
private:
    int score;
    sf::RectangleShape shape;
    float speed;
    int currentWeaponIndex;
};
#endif // PLAYER_H