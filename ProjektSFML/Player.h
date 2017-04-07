#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <time.h>

class Player :
	public Entity
{
private:
	sf::Sprite spriteSheet;
	sf::IntRect rectSourceSprite;
	float playerSpeed;
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
	sf::Texture smokeTex;
	sf::Sprite smokeSprite;
public:
	Player();
	~Player();
	void Update(float dt);
	sf::Sprite getSpriteSheet();
	void setCollided(int tf);
	//bool getWasAttacking();
	//void setWasAttacking(int tf);
	//bool getIsAttacking();
	//void setIsAttacking(int tf);
	int poisonTick(int ticks);
	void poison(int ticks, int damage);
	bool isPoisoned;

	int attack();	
	void recevieDamage(int damage);
	bool death();
	int getHealth() const;
	void setHealth();
	void pushBack(float x, float y);

};

#endif // !PLAYER_H