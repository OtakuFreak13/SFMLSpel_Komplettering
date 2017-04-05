#include <SFML/Graphics.hpp>
#include"Game.h"




int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Får minnesläckor, tror det är enemies som stökar till det för mig.


	
	sf::RenderWindow window(sf::VideoMode(640, 480), "My First SFML Game");
	
	Game game = Game();
	sf::Clock gameTime;
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		int mX = sf::Mouse::getPosition(window).x;
		int mY = sf::Mouse::getPosition(window).y;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			std::cout << "Mouse x: " << mX << endl << "Mouse y: " << mY << endl;
		}
		game.Update(gameTime.restart().asSeconds());
		window.clear();
		window.draw(game);
		window.display();
	}




	//sf::RenderWindow renderWindow(sf::VideoMode(200, 200), "SFML Demo");
	//sf::Event event;
	//sf::CircleShape shape;
	//shape.setRadius(50.f);
	//shape.setPosition(50.f, 50.f);
	//shape.setFillColor(sf::Color::Magenta);

	//while (renderWindow.isOpen())
	//{
	//	while (renderWindow.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::EventType::Closed)
	//		{
	//			renderWindow.close();
	//		}
	//	}
	//	renderWindow.clear();
	//	renderWindow.draw(shape);
	//	renderWindow.display();
	//}

}