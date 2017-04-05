#include "Entity.h"



//void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
//{
//		target.draw(spriteSheet, states);
//}

Entity::Entity()
{
	//texture.loadFromFile(textureFileName);

	//spriteSheet.setTexture(texture);
	//spriteSheet.setTextureRect(sf::IntRect(0, 0, 32, 32));

}


Entity::~Entity()
{

}

//void Entity::setTextureName(string fileName)
//{
//	this->textureFileName = fileName;
//}
//
//string Entity::getTextureName()
//{
//	return this->textureFileName;
//}
//
//void Entity::loadTexture()
//{
//	texture.loadFromFile(getTextureName());
//}
//
//sf::Texture Entity::getTexture()
//{
//	return this->texture;
//}

void Entity::setESpeed(int x)
{
	this->speed = x;
}

void Entity::setEAttackDamage(int x)
{
	this->attackDamage = x;
}

void Entity::setEHealth(int x)
{
	this->health = x;
}

int Entity::getEAttackDamage() const
{
	return this->attackDamage;
}

float Entity::getESpeed() const
{
	return this->speed;
}

int Entity::getEHealth() const
{
	return this->health;
}

//void Entity::setRectSourceSprite(int q, int w, int e, int r)
//{
//	this->rectSourceSprite
//}


