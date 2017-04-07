#ifndef POWER_UP_H
#define POWER_UP_H

#include"SFML\Graphics.hpp"
#include<string>
#include<iostream>

using namespace std;

class PowerUp : public sf::Drawable
{
private:
	int boost;
	sf::CircleShape apple;

public:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	PowerUp();
	~PowerUp();
	void Update(float dt);
	sf::FloatRect getGBounds();

};

#endif // !POWER_UP_H
