#include "SpaceShip.h"

SpaceShip::SpaceShip() : life(3), speed(200), position(0.f, 0.f), weapon(nullptr)
{
}

SpaceShip::~SpaceShip()
{
    if (weapon) {
        delete weapon;
        weapon = nullptr;
    }
}


void SpaceShip::GetStats()
{
    std::cout << "Santé : " << life << "\n Vitesse : " << speed << "\n Arme : " << weapon << std::endl;
}

void SpaceShip::TakeDamage(int damage)
{
    life -= damage;
	if (life < 0)
    {
        life = 0;
    }
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
    return life <= 0;
    
}

void SpaceShip::MoveShape(sf::RectangleShape& shape, const sf::Vector2f& dir)
{
    shape.move(dir);
}
