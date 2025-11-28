#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <vector>

class EnemySpawner
{
public:
    EnemySpawner();
    void SpawnEnemies(int count, float speed);
private:
    int nbEnemies;
    sf::Vector2f positions;
};

#endif // ENEMYSPAWNER_H