#include "SmokeSprite.h"



SmokeSprite::SmokeSprite()
{
	smokeTex.loadFromFile("Image/smoke1.png");
	smokeSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	smokeSprite.setTexture(smokeTex);
	smokeSprite.setPosition(sf::Vector2f(111, 400));
}


SmokeSprite::~SmokeSprite()
{

}

void SmokeSprite::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(smokeSprite, states);
}

void SmokeSprite::Update(sf::Vector2f pos, float dt)
{
	smokeSprite.setPosition(pos);
	//smokeSprite.rotate(10);
}
