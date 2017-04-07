#include "Game.h"
#include<queue>




//int Game::poisonTick(int ticks)
//{
//	//int tick = ticks;
//	//if (ticks-- == 0)
//	//{
//	//	return 0;
//	//}
//
//	//return ticks;
//	if (gameTime.getElapsedTime().asSeconds % 3 == 0 && player.isPoisoned)
//	{
//		
//	}
//	else
//	{
//
//	}
//}
//
//bool Game::poison(int ticks, int damage)
//{
//	//bool poison = true;
//	//if (this->poisonTick(ticks) != 0)
//	//{
//	//	this->player.recevieDamage(damage);
//	//}
//	//else
//	//{
//	//	poison = false;
//	//}
//	//return poison;
//
//}

Game::Game()//kanske ska ha player eller enemy här
{
	//enemyAmount = 20;
	//queue<Enemy> enemies;
	//for (int i = 0; i < enemyAmount; i++)
	//{
	//	enemies.push(Enemy());
	//}

	//this->lengthOfEnemyArr = 10;
	//this->enemies = new Enemy*[this->lengthOfEnemyArr];

	//this->EnemiesInArr = 0;
	//this->enemies[this->EnemiesInArr++] = new Enemy();
	this->gameWon = false;
	this->deaths = 0;

	this->lengthOfEnemyArr = 2;
	this->enemies = new Entity*[this->lengthOfEnemyArr];
	//this->enemies = new Enemy*[this->lengthOfEnemyArr];

	this->enemyAliveArrPlace = 0;
	this->EnemiesInArr = 0;
	for (int i = 0; i < this->lengthOfEnemyArr; i++)
	{
		if (i % 2)
		{
			this->enemies[this->EnemiesInArr++] = new Enemy();
		}
		else
		{
			this->enemies[this->EnemiesInArr++] = new Enemy2();
		}
	}

	aEaten = true;
	gameTime;
	this->gameOverCounter = 0;//TODO kanske ta bort gameOverCounter och set funktionen? Nej behövs för HighScore

	//Enemy *lol = new Enemy();

	//for (int i = 0; i < this->lengthOfEnemyArr; i++)
	//{
	//	this->enemies[i] = new Enemy();
	//}
	sf::FloatRect();
	this->boxULPR = sf::FloatRect(320, -3, 1.0f, 180.0f);
	this->boxULPD = sf::FloatRect(-3, 180, 323.0f, 1.0f);
	this->boxDL = sf::FloatRect(-3, 235, 75.0f, 255.0f);
	this->boxUR = sf::FloatRect(470, -3, 190.0f, 155.0f);
	this->boxMR = sf::FloatRect(445, 155, 250.0f, 155.0f);
	this->boxDRPU = sf::FloatRect(190, 290, 485.0f, 1.0f);
	this->boxDRPL = sf::FloatRect(180, 290, 1.0f, 195.0f);



	backgroundTex.loadFromFile("Image/16bitmap.jpg");
	backgroundSprite.setTexture(backgroundTex);
	
	//anEnPTR = nullptr;
	Enemy2* anEn2PTR = nullptr;
	anEn2PTR = dynamic_cast<Enemy2*>(this->enemies[this->enemyAliveArrPlace]);
	poisonDamage = anEn2PTR->attack();

	//smokeTex.loadFromFile("Image/goblinSwordBlue.png");
	//smokeSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	//smokeSprite.setPosition(sf::Vector2f(111, 400));
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(backgroundSprite, states);
	target.draw(player, states);
	//target.draw(smokeSprite, states);
	if (player.isPoisoned)
	{
		smokesprite.draw(target, states);
	}

	if (!aEaten)
	{
		apple.draw(target, states);//target.draw(apple, states);
	}

	this->renderEnemies(target, states);
	this->gameOver(target, states);

	if (player.getHealth() > 0)
	{
		this->displayGameTime(target, states);
	}
	if (player.getHealth() <= 0 || this->gameWon)
	{
		this->renderHighScore(target, states);
	}
	//target.draw(ball);
}

Game::~Game()
{
	//for (int i = 0; i < this->lengthOfEnemyArr; i++)//this->EnemiesInArr
	for (int i = 0; i < this->EnemiesInArr; i++)//this->EnemiesInArr
	{
		Enemy* anEnPTR = nullptr;
		Enemy2* anEn2PTR = nullptr;
		anEnPTR = dynamic_cast<Enemy*>(this->enemies[i]);
		anEn2PTR = dynamic_cast<Enemy2*>(this->enemies[i]);
		if (anEnPTR != nullptr)
		{
			delete anEnPTR;
		}
		else
		{
			delete anEn2PTR;
		}
	}

	delete[] this->enemies;
}

void Game::Update(float dt)
{
	if (!this->gameWon)
	{
		player.Update(dt);
		this->poisonAttack();
	}
	//enemies[(this->EnemiesInArr - 1) + this->deathCounter()]->Update(dt);

		//enemies[(this->EnemiesInArr - 1)]->Update(dt);
	Enemy* anEnPTR = nullptr;
	Enemy2* anEn2PTR = nullptr;
	anEnPTR = dynamic_cast<Enemy*>(this->enemies[this->enemyAliveArrPlace]);
	anEn2PTR = dynamic_cast<Enemy2*>(this->enemies[this->enemyAliveArrPlace]);
	if (anEnPTR != nullptr)
	{
		anEnPTR->Update(dt);
	}
	else
	{
		anEn2PTR->Update(dt);
	}

	if (!player.death() || this->gameWon)
	{
		collision();
	}

	if (anEnPTR != nullptr)
	{
		if (anEnPTR->death()) {

			//this->EnemiesInArr--;
			if (this->enemyAliveArrPlace + 1 != this->lengthOfEnemyArr)
			{
				this->enemyAliveArrPlace++;
				this->deaths++;
			}
			else if (this->enemyAliveArrPlace + 1 == this->lengthOfEnemyArr && !this->gameWon)
			{
				//this->enemyAliveArrPlace = 0; //oändligt med fiender?
				this->gameWon = true;
				this->deaths++;
			}
			//Enemy *myEnemy = new Enemy();

			//enemies[EnemiesInArr - 1] = myEnemy;

			//int deaths = this->deathCounter();
			//int arrPos = (this->EnemiesInArr - 1);
			//enemies[arrPos + deaths] = new Enemy();
		}
	}
	else
	{
		if (anEn2PTR->death()) {

			//this->EnemiesInArr--;
			if (this->enemyAliveArrPlace + 1 != this->lengthOfEnemyArr)
			{
				this->enemyAliveArrPlace++;
				this->deaths++;
			}
			else if (this->enemyAliveArrPlace + 1 == this->lengthOfEnemyArr && !this->gameWon)
			{
				//this->enemyAliveArrPlace = 0; //oändligt med fiender?
				this->gameWon = true;
				this->deaths++;
			}
			//Enemy *myEnemy = new Enemy();

			//enemies[EnemiesInArr - 1] = myEnemy;

			//int deaths = this->deathCounter();
			//int arrPos = (this->EnemiesInArr - 1);
			//enemies[arrPos + deaths] = new Enemy();
		}
	}
	//this->deathCounter();
	if (gameOverCounter == 0)
	{
		this->intGameTime = this->gameTime.getElapsedTime();
	}
	setGameOverCounter();

	if (gameOverCounter == 1)
	{
		highScore.save(this->deaths, intGameTime.asSeconds());
		highScore.load();
	}
	float xx = player.getSpriteSheet().getPosition().x;
	float yy =player.getSpriteSheet().getPosition().y;
	sf::Vector2f xy(xx + 15, yy + 15);
	smokesprite.Update(xy, dt);//spriteSheet.getPosition());

}

void Game::poisonAttack()
{
	int timy = gameTime.getElapsedTime().asMilliseconds();
	if (timy % 3000 == 0 && player.isPoisoned)
	{
		Enemy2* anEn2PTR = nullptr;
		anEn2PTR = dynamic_cast<Enemy2*>(this->enemies[this->enemyAliveArrPlace]);
		player.poison(5/*anEn2PTR->getTicks()*/, poisonDamage);
	}
}

void Game::setGameOverCounter()
{
	if (player.death() || this->gameWon)
	{
		this->gameOverCounter++;
	}
}

int Game::getDeathCounter()
{
	return this->deathCounter();
}

int Game::deathCounter()
{
	//int deaths = 0;
	//for (int i = 0; i < this->EnemiesInArr; i++)
	//{
	//	if (enemies[i]->death()) //== true
	//	{
	//		deaths++;
	//	}
	//}
	Enemy* anEnPTR = nullptr;
	Enemy2* anEn2PTR = nullptr;
	anEnPTR = dynamic_cast<Enemy*>(this->enemies[this->enemyAliveArrPlace]);

	if (anEnPTR != nullptr)
	{
		if (anEnPTR->death())
		{
			this->deaths++;
		}
	}
	else
	{
		anEn2PTR = dynamic_cast<Enemy2*>(this->enemies[this->enemyAliveArrPlace]);
		if (anEn2PTR->death())
		{
			deaths++;
		}
	}
	return deaths;
}

void Game::renderEnemies(sf::RenderTarget & target, sf::RenderStates states) const
{
	//for (int i = 0; i < this->EnemiesInArr; i++) {

	//	//if (!this->enemies[i]->death()) {
	//	target.draw(*enemies[i], states);
	//	//}
	//}
	target.draw(*enemies[this->enemyAliveArrPlace]);
}

void Game::renderHighScore(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Font font;
	//	if (!font.loadFromFile("Image/monks_writing/MonksWriting.ttf"))
	if (!font.loadFromFile("Image/feather_script/FeatherScript.otf")) //enklare att läsa
	{
		// error...
	}
	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font


	string textString = "HighScore List: \n" + highScore.getHighScore();
	// set the string to display
	text.setString(textString);

	// set the character size
	text.setCharacterSize(18); // in pixels, not points!

							   // set the color
	text.setFillColor(sf::Color::Black);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.move(350.0f, 20.0f);
	target.draw(text, states);
}

int Game::displayGameTime(sf::RenderTarget & target, sf::RenderStates states) const
{



	sf::Font font;
	//	if (!font.loadFromFile("Image/monks_writing/MonksWriting.ttf"))
	if (!font.loadFromFile("Image/feather_script/FeatherScript.otf")) //enklare att läsa
	{
		// error...
	}
	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font


	string textString = to_string(intGameTime.asSeconds());
	// set the string to display
	text.setString(textString);

	// set the character size
	text.setCharacterSize(18); // in pixels, not points!

							   // set the color
	text.setFillColor(sf::Color::Black);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.move(20.0f, 20.0f);
	target.draw(text, states);

	return intGameTime.asSeconds();
}

void Game::gameOver(sf::RenderTarget & target, sf::RenderStates states) const
{

	if (this->player.getHealth() <= 0 || this->gameWon)
	{
		sf::Font font;
		//	if (!font.loadFromFile("Image/monks_writing/MonksWriting.ttf"))
		if (!font.loadFromFile("Image/feather_script/FeatherScript.otf")) //enklare att läsa
		{
			// error...
		}
		sf::Text text;

		// select the font
		text.setFont(font); // font is a sf::Font

		int kills = this->deaths;
		int highscore = kills * this->intGameTime.asSeconds() / 5;

		string textString;
		if (this->gameWon)
		{
			textString = "All enemies are killed! You have won!!! \nConfirmed kills: " + to_string(kills) + "\nTime in game; " + to_string(this->intGameTime.asSeconds()) + " seconds" + "\nHighscore: " + to_string(highscore);
		}
		else
		{
			textString = "Player is dead! \nConfirmed kills: " + to_string(kills) + "\nTime in game; " + to_string(this->intGameTime.asSeconds()) + " seconds" + "\nHighscore: " + to_string(highscore);
		}
		// set the string to display
		text.setString(textString);

		// set the character size
		text.setCharacterSize(24); // in pixels, not points!

								   // set the color
		text.setFillColor(sf::Color::Black);

		// set the text style
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		text.move(150.0f, 150.0f);
		target.draw(text, states);
	}
}

bool Game::bounds(int x, int y)
{
	//sf::IntRect boxUR(-3, -3, 355, 230);
	//sf::IntRect boxDR(-3, 235, 105, 255);
	//sf::IntRect boxUL(450, -3, 190, 155);
	//sf::IntRect boxML(420, 155, 250, 155);
	//sf::IntRect boxDL(165, 290, 485, 195);
	//box1.width = 100;
	//box1.height = 250;
	//box1.
	bool outOfBounds = false;
	if (x < 100 && 230 < y < 480)
	{
		true;
	}
	else if (x < 350 && y < 225)
	{
		true;
	}
	else if (x > 265 && 300 < y)
	{
		true;
	}
	else if (x > 420 && 155 < y)
	{
		true;
	}
	else if (x < 400 && y < 150)
	{
		true;
	}
	return outOfBounds;
}

void  Game::collision()//BOOL poison på player från andra fiende.
{

	sf::Time delayInt = this->delayTime.restart(); //.asSeconds()
	time += delayInt;
	time2 += delayInt;

	Enemy* anEnPTR = nullptr;
	Enemy2* anEn2PTR = nullptr;
	anEnPTR = dynamic_cast<Enemy*>(this->enemies[this->enemyAliveArrPlace]);
	if (anEnPTR != nullptr)
	{
		//if (deathCounter()>0 && deathCounter() % 5 == 0)
		//{
		//	this->player.setHealth();
		//}

		//for (int i = 0; i < this->EnemiesInArr; i++)
		//{
		if (anEnPTR->death()) {
			//do nothign
		}
		else if (player.getSpriteSheet().getGlobalBounds().intersects(anEnPTR->getSpriteSheet().getGlobalBounds()))
		{
			//std::cout << "The sprites have collided!" << endl;
			//player.setCollided(true);
			//enemy.setCollided(true); 

			if (this->time.asSeconds() >= 2)
			{
				if (/*!player.getWasAttacking() && !player.getIsAttacking() && */sf::Keyboard::isKeyPressed(sf::Keyboard::Space)  /*sf::Keyboard::isKeyPressed(sf::Keyboard::Space)*/)
				{
					anEnPTR->recevieDamage(player.attack());
					//player.setIsAttacking(true);
					time = sf::Time();
					//delay.restart();

				}
				/*		else if (!player.getWasAttacking() && player.getIsAttacking())
						{
							player.setIsAttacking(false);
							player.setWasAttacking(true);
						}
						else
						{
							player.setWasAttacking(false);
						}*/
				if (/*!enemy.getWasAttacking() && !enemy.getIsAttacking()*/this->time2.asSeconds() >= 2.5 && anEnPTR->getHealth() > 0 /*&& sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)*/)
				{

					player.recevieDamage(anEnPTR->attack());
					//enemies[i]->setIsAttacking(true);
					time2 = sf::Time();
				}
				//else
				//{
				//	enemies[i]->setIsAttacking(false);

				//}
			}

			//sf::Event event();
			//sf::Event::KeyReleased;	
			//bool wasButtonReleased = false;
			//switch (event().key.code)
			//{
			//case sf::Keyboard::Space:
			//	wasButtonReleased = true;
			//	break;

			//default:
			//	break;
			//}


			//if (event.type == sf::Event::KeyReleased)
			//{
			//	if (event.key.code == sf::Keyboard::Space)
			//	{

			//	}
			//}

		}
	}
	else
	{
		anEn2PTR = dynamic_cast<Enemy2*>(this->enemies[this->enemyAliveArrPlace]);
		if (anEn2PTR->death()) {
			//do nothign
		}
		else if (player.getSpriteSheet().getGlobalBounds().intersects(anEn2PTR->getSpriteSheet().getGlobalBounds()))
		{

			if (this->time.asSeconds() >= 2)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					anEn2PTR->recevieDamage(player.attack());
					//player.setIsAttacking(true);
					time = sf::Time();
					//delay.restart();

				}

				if (!player.isPoisoned && this->time2.asSeconds() >= 4 && anEn2PTR->getHealth() > 0)
				{
					player.isPoisoned = true;
					poisonAttack();
					//player.poison(ticks, anEn2PTR->attack());
					//poison(anEn2PTR->attack(), ticks);
					//player.recevieDamage(anEn2PTR->attack());
					//enemies[i]->setIsAttacking(true);
					time2 = sf::Time();
				}
			}
		}
	}
	//}

	//else
	//{
	//	player.setCollided(false);
	//	enemy.setCollided(false);
	//}
	//sf::IntRect boxUR(-3, -3, 355, 230);
	//sf::IntRect boxDR(-3, 235, 105, 255);
	//sf::IntRect boxUL(450, -3, 190, 155);
	//sf::IntRect boxML(420, 155, 250, 155);
	//sf::IntRect boxDL(165, 290, 485, 195);
	//sf::FloatRect

	if (player.getSpriteSheet().getGlobalBounds().intersects(boxULPD))
	{
		int x = player.getSpriteSheet().getPosition().x;
		int y = player.getSpriteSheet().getPosition().y + 5;
		//	cout << "Push boxULPD!" << endl;
		player.pushBack(x, y);
		//player.getSpriteSheet().setPosition(x, y);
	}
	if (player.getSpriteSheet().getGlobalBounds().intersects(boxULPR))
	{
		int x = player.getSpriteSheet().getPosition().x + 5;
		int y = player.getSpriteSheet().getPosition().y;
		//	cout << "Push boxULPR!" << endl;
		player.pushBack(x, y);
		//player.getSpriteSheet().setPosition(x, y);
	}
	if (player.getSpriteSheet().getGlobalBounds().intersects(boxDL))
	{
		int x = player.getSpriteSheet().getPosition().x + 5;
		int y = player.getSpriteSheet().getPosition().y;
		//	cout << "Push boxDLPR!" << endl;
		player.pushBack(x, y);
		//player.getSpriteSheet().setPosition(x, y);
	}
	if (player.getSpriteSheet().getGlobalBounds().intersects(boxUR))
	{
		int x = player.getSpriteSheet().getPosition().x - 5;
		int y = player.getSpriteSheet().getPosition().y;
		//	cout << "Push boxURPL!" << endl;
		player.pushBack(x, y);
		//player.getSpriteSheet().setPosition(x, y);
	}
	if (player.getSpriteSheet().getGlobalBounds().intersects(boxMR))
	{
		int x = player.getSpriteSheet().getPosition().x - 5;
		int y = player.getSpriteSheet().getPosition().y;
		//	cout << "Push boxMRPL!" << endl;
		player.pushBack(x, y);
		//player.getSpriteSheet().setPosition(x, y);
	}
	if (player.getSpriteSheet().getGlobalBounds().intersects(boxDRPL))
	{
		int x = player.getSpriteSheet().getPosition().x - 5;
		int y = player.getSpriteSheet().getPosition().y;
		//	cout << "Push boxDRPL!" << endl;
		player.pushBack(x, y);
		//player.getSpriteSheet().setPosition(x, y);
	}
	if (player.getSpriteSheet().getGlobalBounds().intersects(boxDRPU))
	{
		int x = player.getSpriteSheet().getPosition().x;
		int y = player.getSpriteSheet().getPosition().y - 5;
		//	cout << "Push boxDRPU!" << endl;
		player.pushBack(x, y);
		//player.getSpriteSheet().setPosition(x, y);
	}

	int aTime = gameTime.getElapsedTime().asMilliseconds();
	if (aEaten && ((aTime % 5000) == 0))
	{
		aEaten = false;
		cout << "An apple has appeard! " <</* aTime <<*/ endl;
	}
	//gameTime.getElapsedTime().asSeconds == fmod(10, 2);
	if ((!aEaten) && apple.getGBounds().intersects(player.getSpriteSheet().getGlobalBounds()))
	{

		cout << "Player healed for 5hp! \nRemaining player health: " << player.getHealth() << endl;
		player.setHealth();
		aEaten = true;
		player.isPoisoned = false;
	}

}
