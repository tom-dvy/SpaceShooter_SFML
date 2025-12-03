#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <random>

Enemy::Enemy()
{
    speed = 150.0f;

    shape.setSize(sf::Vector2f(50.0f, 30.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(shape.getSize() / 2.f);
    
    // Position aléatoire en haut de l'écran
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(50.0f, 950.0f);
    std::uniform_real_distribution<> shootDis(0.5f, 3.0f);
    
    shape.setPosition(dis(gen), 50.0f);
    
    // Délai de tir aléatoire pour chaque ennemi
    shootCooldown = shootDis(gen);
    shootTimer = 0.0f;

    weapon = std::make_unique<Weapon>(1, 100, 2.0f);
}

void Enemy::AiMove(sf::RenderWindow &window)
{
    sf::Vector2f movement(0.0f, 0.0f);

    // Mouvement horizontal
    movement.x += speed * direction * (1.0f / 60.0f);

    Move(movement, shape, window);

    // Vérifier les limites horizontales et descendre plus quand on touche les bords
    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f half = shape.getSize() / 2.f;
    sf::Vector2u win = window.getSize();

    if (pos.x <= half.x)
    {
        direction = 1.0f;
        // Descendre quand on touche le bord gauche
        Move(sf::Vector2f(0.0f, 50.0f), shape, window);
    }
    else if (pos.x >= static_cast<float>(win.x) - half.x)
    {
        direction = -1.0f;
        // Descendre quand on touche le bord droit
        Move(sf::Vector2f(0.0f, 50.0f), shape, window);
    }
}

void Enemy::AiShoot()
{
    // Gérer le cooldown de tir
    shootTimer += 1.0f / 60.0f;
    
    Weapon *w = GetWeapon();
    if (w && shootTimer >= shootCooldown)
    {
        w->Shoot(shape.getPosition(), sf::Vector2f(0.0f, 1.0f));
        shootTimer = 0.0f;
    }
}

void Enemy::Display(sf::RenderWindow &window)
{
    window.draw(shape);
}