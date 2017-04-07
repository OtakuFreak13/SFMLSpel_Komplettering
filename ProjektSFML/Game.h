#ifndef GAME_H
#define GAME_H
#include "SFML\Graphics.hpp"
#include"Player.h"
#include"Enemy.h"
#include<iostream>
#include"HighScore.h"
#include"PowerUp.h"
#include<math.h>
#include"Enemy2.h"
#include"SmokeSprite.h"

class Game :public sf::Drawable //TODO Kolla efter onödiga funktioner speciellt i player, enemy och game
{
private:
	sf::Texture backgroundTex;
	sf::Sprite backgroundSprite;
	Player player;
	//Enemy enemies[10];
	int EnemiesInArr;
	int enemyAliveArrPlace;
	Entity * *enemies;
	//Enemy* *enemies;
	sf::CircleShape ball;
	HighScore highScore;

	int deathCounter();
	int deaths;
	int lengthOfEnemyArr;
	int gameOverCounter;
	bool gameWon;

	void renderEnemies(sf::RenderTarget & target, sf::RenderStates states) const;
	void renderHighScore(sf::RenderTarget & target, sf::RenderStates states) const;

	sf::Clock gameTime;
	sf::Time intGameTime;

	sf::Clock delayTime;
	sf::Time time;
	sf::Time time2;

	int displayGameTime(sf::RenderTarget & target, sf::RenderStates states) const;

	void gameOver(sf::RenderTarget & target, sf::RenderStates states) const;

	bool bounds(int x, int y);
	void collision();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::FloatRect boxULPD;
	sf::FloatRect boxULPR;
	sf::FloatRect boxDL;
	sf::FloatRect boxUR;
	sf::FloatRect boxMR;
	sf::FloatRect boxDRPL;
	sf::FloatRect boxDRPU;

	PowerUp apple;
	bool aEaten;
	void poisonAttack();
	//int poisonTick(int ticks);
	//bool poison(int ticks, int damage);
	//sf::Texture smokeTex;
	SmokeSprite smokesprite;
	int poisonDamage;
public:
	Game();
	~Game();
	void Update(float dt);
	void setGameOverCounter();
	int getDeathCounter();
};

#endif //  !GAME_H