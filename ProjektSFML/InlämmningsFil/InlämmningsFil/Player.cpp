#include "Player.h"


Player::Player(): Entity()
{
	texture.loadFromFile("Image/goblinsword.png");
	
	spriteSheet.setTexture(texture);
	spriteSheet.setTextureRect(sf::IntRect(0, 0, 64, 64));
	spriteSheet.setPosition(sf::Vector2f(111, 400));
	currentKeyFrame = sf::Vector2i(0, 0);
	keyFrameSize = sf::Vector2i(64, 64);
	spriteSheetWidth = 7;
	
	animationSpeed = 0.1f;
	keyFrameDuration = 0.0f;

	setESpeed(180.0f);
	playerSpeed = getESpeed();

	srand(time(NULL));
	setEAttackDamage(2);
	attackDamage = getEAttackDamage(); //inte helt säker på hur/var jag ska ha health och damage 
	setEHealth(15);
	health = getEHealth();

	
}


void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(spriteSheet, states);
}

Player::~Player()
{
	
}

void Player::Update(float dt)
{
	float x = 1.0f;
	float y = 1.0f;
	sf::Vector2f direction(0.0f, 0.0f);

	if (this->health <= 0)
	{
		// death animation
		currentKeyFrame.y = 4;
		keyFrameDuration += dt;// 5 * dt;
		if (keyFrameDuration >= animationSpeed)
		{
			currentKeyFrame.x++;

			if (currentKeyFrame.x >= 4)
			{
				currentKeyFrame.x = 4;
			}

			spriteSheet.setTextureRect(sf::IntRect(currentKeyFrame.x * keyFrameSize.x, currentKeyFrame.y * keyFrameSize.y, keyFrameSize.x, keyFrameSize.y));
			keyFrameDuration = 0.0f;
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			//std::cout << "Player Moved Left" << endl;
			direction.x = -x;
			keyFrameDuration += dt;
			currentKeyFrame.y = 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			direction.x = x;
			keyFrameDuration += dt;
			currentKeyFrame.y = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			direction.y = y;
			keyFrameDuration += dt;
			currentKeyFrame.y = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			direction.y = -y;
			keyFrameDuration += dt;
			currentKeyFrame.y = 2;
		}



		spriteSheet.move(direction * playerSpeed * dt);

		// Update animation
		if (keyFrameDuration >= animationSpeed)
		{
			currentKeyFrame.x++;

			if (currentKeyFrame.x >= spriteSheetWidth)
			{
				currentKeyFrame.x = 0;
			}

			spriteSheet.setTextureRect(sf::IntRect(currentKeyFrame.x * keyFrameSize.x, currentKeyFrame.y * keyFrameSize.y, keyFrameSize.x, keyFrameSize.y));
			keyFrameDuration = 0.0f;
		}

		//if (collided == true && !wasAttacking && !isAttacking && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		//{
		//	isAttacking = true;
		//}

		if (isAttacking)
		{
			this->attack();
		}
	}
}

sf::Sprite Player::getSpriteSheet()
{
	return this->spriteSheet;
}

void Player::setCollided(int tf)
{
	this->collided = tf;
}

//bool Player::getWasAttacking()
//{
//	return this->wasAttacking;
//}
//
//void Player::setWasAttacking(int tf)
//{
//	this->wasAttacking = tf;
//}
//
//bool Player::getIsAttacking()
//{
//	return this->isAttacking;
//}
//
//void Player::setIsAttacking(int tf)
//{
//	this->isAttacking = tf;
//}

int Player::attack()
{
	//animate attack
	int randNum = rand() % 3;
	return attackDamage * randNum;
}

void Player::recevieDamage(int damage)
{
	this->health -= damage;
	cout << damage << " Amount of damage player has revcieved! Remaining player health: " << this->health << endl;
	if (this->health == 0)
	{
		this->death();
	}
}

bool Player::death()
{
	bool dead = false;
	if (this->health <= 0)
	{
		dead = true;
	}

	return dead;
}

int Player::getHealth() const
{
	return this->health;
}

void Player::setHealth()
{
	this->health += 5;
}
