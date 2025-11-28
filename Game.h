#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <vector>

class Game
{
public:
    Game();
    void Start();
    void NextLevel();
    void Respawn();
    void IsGameOver();

    struct  Level
    {
        int levelID;
        int enemyCount;
        float enemySpeed;
    };

private:
    int score;
    int wave;
    int playerLives;
};

#endif // GAME_H