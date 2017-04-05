#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <time.h>
class Enemy :
	public Entity
{
private:
	sf::Sprite spriteSheet;
	sf::IntRect rectSourceSprite;
	float enemySpeed;
	sf::Texture texture;

	sf::Vector2i currentKeyFrame;
	sf::Vector2i keyFrameSize;
	int spriteSheetWidth;
//	int spriteSheetHeight;
	float animationSpeed;
	float keyFrameDuration;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	int attackDamage;
	int health;
	bool collided = false;
	bool wasAttacking = false;
	bool isAttacking = false;
public:
	Enemy();
	~Enemy();
	void move(float dt);
	void Update(float dt);
	sf::Sprite getSpriteSheet();
	void setCollided(int tf);
	//bool getWasAttacking();
	//void setWasAttacking(int tf);
	//bool getIsAttacking();
	//void setIsAttacking(int tf);
	int attack();
	void recevieDamage(int damage);
	bool death() const;
	int getHealth();
};

#endif // !ENEMY_H