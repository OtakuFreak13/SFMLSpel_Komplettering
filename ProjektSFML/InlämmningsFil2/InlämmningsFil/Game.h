#ifndef GAME_H
#define GAME_H
#include "SFML\Graphics.hpp"
#include"Player.h"
#include"Enemy.h"
#include<iostream>
#include"HighScore.h"

class Game :public sf::Drawable //TODO Kolla efter onödiga funktioner speciellt i player, enemy och game
{
private:
	sf::Texture backgroundTex;
	sf::Sprite backgroundSprite;
	Player player;
	//Enemy enemies[10];
	int EnemiesInArr;
	Enemy* *enemies;
	sf::CircleShape ball;
	HighScore highScore;

	int deathCounter() const;
	int lengthOfEnemyArr;
	int gameOverCounter;

	void renderEnemies(sf::RenderTarget & target, sf::RenderStates states) const;
	void renderHighScore(sf::RenderTarget & target, sf::RenderStates states) const;

	sf::Clock gameTime;
	sf::Time intGameTime;

	sf::Clock delayTime;
	sf::Time time;
	sf::Time time2;

	int displayGameTime(sf::RenderTarget & target, sf::RenderStates states) const;

	void gameOver(sf::RenderTarget & target, sf::RenderStates states) const;

	void collision();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Game();
	~Game();
	void Update(float dt);
	void setGameOverCounter();
	int getDeathCounter() const;
};

#endif //  !GAME_H