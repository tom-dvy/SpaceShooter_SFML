#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Projectiles.h"
#include "Enemy.h"

class Game
{
public:
    Game();
    ~Game();
    void Start();
    void NextLevel();
    void Respawn();
    void IsGameOver();

private:
    int score;
    int wave;
    int playerLives;
    std::vector<Projectile> projectiles;
};

#endif // GAME_H