#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <windows.h>

#include <vector>
#include "Player.h"
#include "Projectiles.h"
#include "Enemy.h"

class Game
{
public:
    Game(int numberOfEnemies = 5);
    ~Game();
    void Start();
    void NextLevel();

private:
    void HandleEvents(sf::RenderWindow& window);
    void Update(Player& player, float deltaTime, sf::RenderWindow& window, bool &isGameOver);
    void Render(sf::RenderWindow& window, Player& player, bool isGameOver);

private:
    int score;
    int wave;
    int playerLives;
    std::vector<Projectile> projectiles;
    std::vector<Enemy> enemies;
    int nbEnemies;
    sf::Font font;
};

#endif // GAME_H