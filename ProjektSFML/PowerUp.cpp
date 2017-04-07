#include "PowerUp.h"



void PowerUp::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(apple, states);
}

PowerUp::PowerUp()
{
	float radius = 5;
	apple = sf::CircleShape(radius);
	apple.setFillColor(sf::Color::Red);
	apple.setPosition(333, 175);
	

}


PowerUp::~PowerUp()
{
}

void PowerUp::Update(float dt)
{

}

sf::FloatRect PowerUp::getGBounds()
{
	return this->apple.getGlobalBounds();
}
