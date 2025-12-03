#include "SpaceShip.h"

SpaceShip::SpaceShip() : life(3), speed(200), position(0.f, 0.f), weapon(nullptr)
{
}

void SpaceShip::GetStats()
{
    std::cout << "Santé : " << life << "\n Vitesse : " << speed << "\n Arme : " << weapon.get() << std::endl;
}

void SpaceShip::TakeDamage(int damage, sf::RectangleShape& shape)
{
    life -= damage;
    if (life < 0)
    {
        life = 0;
    }
    
    // shape transparente en fonction des vies restantes
    sf::Color color = shape.getFillColor();
    if (life == 2)
    {
        color.a = 200;  // 80% opacité (1 coup pris)
    }
    else if (life == 1)
    {
        color.a = 150;  // 60% opacité (2 coups pris)
    }
    else if (life == 0)
    {
        color.a = 100;  // 40% opacité (3 coups pris - mort)
    }
    shape.setFillColor(color);
}

void SpaceShip::Move(const sf::Vector2f& direction, sf::RectangleShape& shape, const sf::RenderWindow& window)
{
	position += direction;

    shape.move(direction);

    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f half = shape.getSize() / 2.f;
    sf::Vector2u win = window.getSize();

    // Pour empêcher le vaisseau de sortir de l'écran
    if (pos.x < half.x) 
    {
        pos.x = half.x;
    }
    if (pos.x > static_cast<float>(win.x) - half.x) 
    {
        pos.x = static_cast<float>(win.x) - half.x;
    }
    if (pos.y < half.y) 
    {
        pos.y = half.y;
    }
    if (pos.y > static_cast<float>(win.y) - half.y) 
    {
        pos.y = static_cast<float>(win.y) - half.y;
    }

    shape.setPosition(pos);
}

bool SpaceShip::IsDead() const
{  

    if (life <= 0)   
    {
        std::cout << "Mort" << std::endl;
    }
    return life <= 0;
}