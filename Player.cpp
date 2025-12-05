#include <SFML/Graphics.hpp>
#include "Player.h"
#include "MachineGun.h"
#include "Gun.h"
#include <iostream>

Player::Player() : currentWeaponIndex(0)
{
    score = 0;
    speed = 300.0f;
    life = 3;

    shape.setSize(sf::Vector2f(50.f, 30.f));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getSize() / 2.0f);
    shape.setPosition(500.f, 700.f);

    // Initialiser avec le Gun par défaut
    SetWeapon(new Weapon(1, 10, 0.5f));

    SpaceShip::GetStats();

    // std::cout << "Player::Player this=" << this << " weapon=" << weapon << std::endl;
}

void Player::SetScore(int scorePlayer, sf::Font font, sf::RenderWindow& window)
{
    // Gestion du score du joueur
    score = scorePlayer;

    // Affichage du score
    sf::Text scoreText("Score : " + std::to_string(score), font, 30);
    scoreText.setFillColor(sf::Color::White);

    scoreText.setPosition(
        10.0f,
        10.0f);

    window.draw(scoreText);
}

void Player::GetMoveInput(const sf::RenderWindow &window)
{
    const float direction = 1.0f / 60.0f;
    sf::Vector2f movement(0.0f, 0.0f);

    // Déplacement à gauche
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        movement.x -= speed * direction;
    }

    // Déplacement à droite
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += speed * direction;
    }

    // Déplacement en haut
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        movement.y -= speed * direction;
    }

    // Déplacement en bas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += speed * direction;
    }

    Move(movement, shape, window);
}

void Player::GetShootInput()
{
    // Gestion des tirs du joueur
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Weapon *w = GetWeapon();
        if (w)
        {
            w->Shoot(shape.getPosition(), sf::Vector2f(0.0f, -1.0f));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        Weapon *w = GetWeapon();
        if (w)
        {
            w->Reload();
        }
    }
}

void Player::HandleWeaponSwitch()
{
    // Touche 1 = Gun basique
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        if (currentWeaponIndex != 0)
        {
            currentWeaponIndex = 0;
            SetWeapon(new Gun());
            std::cout << "Arme équipée : Gun (3 dégât, 10 munitions, 0.5s cadence de tir)" << std::endl;
        }
    }
    
    // Touche 2 = Mitrailleuse
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        if (currentWeaponIndex != 1)
        {
            currentWeaponIndex = 1;
            SetWeapon(new MachineGun());
            std::cout << "Arme équipée : MachineGun (1 dégâts, 50 munitions, 0.1s cadence de tir)" << std::endl;
        }
    }
}

void Player::Display(sf::RenderWindow &window)
{
    window.draw(shape);
}

const sf::FloatRect Player::GetBounds() const
{
    return shape.getGlobalBounds();
}

void Player::Respawn()
{
    life = 3;
    shape.setPosition(500.f, 700.f);
    std::cout << "Player a respawn. Vies : " << life << std::endl;

    // Remettre le Player de la bonne opacité
    sf::Color color = shape.getFillColor();
    color.a = 250;
    shape.setFillColor(color);
}