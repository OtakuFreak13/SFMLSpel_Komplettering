#pragma once
#include "Entity.h"
#include <time.h>
#include <random>

class Enemy2 :
	public Entity
{
private:
	sf::Sprite spriteSheet;
	sf::Texture texture;

	sf::Vector2i currentKeyFrame;
	sf::Vector2i keyFrameSize;
	int spriteSheetWidth;
	float animationSpeed;
	float keyFrameDuration;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;


	int attackDamage;
	int ticks;
	int health;

	bool bounds(int x, int y);
public:
	Enemy2();
	~Enemy2();

	void Update(float dt);

	sf::Sprite getSpriteSheet();

	int attack();
	void recevieDamage(int damage);
	bool death() const;
	int getHealth();
	int getTicks();
};

