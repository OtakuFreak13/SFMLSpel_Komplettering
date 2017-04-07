#include "Enemy2.h"



Enemy2::Enemy2()
{
	srand(time(NULL));

	std::random_device rd;

	std::default_random_engine *generator = new std::default_random_engine(rd());



	int PosXRand;
	int PosYRand;
	do
	{
		std::uniform_int_distribution<int> PosXRandDIST(20, 560);
		std::uniform_int_distribution<int> PosYRandDIST(20, 420);
		PosXRand = PosXRandDIST(*generator);
		PosYRand = PosYRandDIST(*generator);
	} while (this->bounds(PosXRand, PosYRand));


	if (!texture.loadFromFile("Image/goblinSwordRed.png"))
	{
		// handle error
	}
	spriteSheet.setTexture(texture);
	spriteSheet.setTextureRect(sf::IntRect(0, 0, 64, 64));
	spriteSheet.setPosition(sf::Vector2f(PosXRand, PosYRand));
	currentKeyFrame = sf::Vector2i(0, 0);
	keyFrameSize = sf::Vector2i(64, 64);
	spriteSheetWidth = 7;
	animationSpeed = 0.1f;
	keyFrameDuration = 0.0f;


	std::uniform_int_distribution<int> attackDamageDIST(1, 3);
	setEAttackDamage(attackDamageDIST(*generator));// (rand() % 3) + 1;
	attackDamage = getEAttackDamage();
	setEHealth(attackDamageDIST(*generator) * 3);
	health = getEHealth();//(rand() % 10) + 1;	
	this->ticks = 5;

	delete generator;
}


Enemy2::~Enemy2()
{
}

void Enemy2::Update(float dt)
{
	if (this->health <= 0)
	{
		// death animation
		currentKeyFrame.y = 4;
		keyFrameDuration += dt;// 5 * dt;
		if (keyFrameDuration >= animationSpeed)
		{
			currentKeyFrame.x++;

			if (currentKeyFrame.x >= 5)
			{
				currentKeyFrame.x = 5;
			}

			spriteSheet.setTextureRect(sf::IntRect(currentKeyFrame.x * keyFrameSize.x, currentKeyFrame.y * keyFrameSize.y, keyFrameSize.x, keyFrameSize.y));
			keyFrameDuration = 0.0f;
		}
	}
}

void Enemy2::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(spriteSheet, states);
}

sf::Sprite Enemy2::getSpriteSheet()
{
	return this->spriteSheet;
}

int Enemy2::attack()
{
	//animate attack
	std::random_device rd;

	std::default_random_engine *generator = new std::default_random_engine(rd());
	std::uniform_int_distribution<int> attackDIST(0, 2);

	int randNum = attackDIST(*generator);
	delete generator;

	return attackDamage * randNum / 2;
	//delete generator;
}

void Enemy2::recevieDamage(int damage)
{
	this->health -= damage;
	cout << damage << " Amount of damage enemy has revcieved! Remaining enemy health: " << this->health << endl;

	this->death();
}

bool Enemy2::death() const
{
	bool dead = false;
	if (this->health <= 0)
	{
		dead = true;
	}

	return dead;
}

int Enemy2::getHealth()
{
	return this->health;
}

int Enemy2::getTicks()
{
	return this->ticks;
}


bool Enemy2::bounds(int x, int y)
{
	bool outOfBounds = false;
	if (x < 100 && 230 < y < 480)
	{
		cout << "Box DL" << endl;
		outOfBounds = true;
	}
	else if (x < 350 && y < 225)
	{
		cout << "Box UL" << endl;
		outOfBounds = true;
	}
	else if (x > 150 && 260 < y)
	{
		cout << "Box DR" << endl;
		outOfBounds = true;
	}
	else if (x > 400 && 155 < y)
	{
		cout << "Box ML" << endl;
		outOfBounds = true;
	}
	else if (x > 435 && y < 155)
	{
		cout << "Box UR" << endl;
		outOfBounds = true;
	}
	else {
		cout << "No Box x:" << x << "y:" << y << endl;
	}
	return outOfBounds;
}