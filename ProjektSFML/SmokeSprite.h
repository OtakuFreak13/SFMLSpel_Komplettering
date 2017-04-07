#ifndef SMOKE_SPRITE_H
#define SMOKE_SPRITE_H
#include"SFML\Graphics.hpp"
class SmokeSprite :public sf::Drawable
{
private:
	sf::Texture smokeTex;
	sf::Sprite smokeSprite;
public:
	SmokeSprite();
	~SmokeSprite();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	void Update(sf::Vector2f pos, float dt);

};

#endif