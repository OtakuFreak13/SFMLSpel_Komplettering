#ifndef ENTITY_H
#define ENTITY_H

#include"SFML\Graphics.hpp"
#include<string>
#include<iostream>

using namespace std;

class Entity :public sf::Drawable
{
private:
	//sf::Texture texture;
	//string textureFileName;
	//sf::Sprite spriteSheet; //kanske ska vara här inte säker
	//sf::RectangleShape rect;
	//sf::IntRect rectSourceSprite;

	int health;
	int attackDamage;
	float speed;
	//void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Entity();
	virtual ~Entity();
	//virtual void Update(float dt, float x = 1.0f, float y = 1.0f) = 0;//Om jag inte ska ha denna klass för items så kan jag ha med denna raden.
	//void setTextureName(string fileName);
	//string getTextureName();
	//void loadTexture();
	//sf::Texture getTexture();
	//void setRectSourceSprite(int q, int w, int e, int r);
	void setESpeed(int x);
	void setEAttackDamage(int x);
	void setEHealth(int x);
	int getEAttackDamage()const;
	float getESpeed()const;
	int getEHealth()const;
};

#endif // !ENTITY_H