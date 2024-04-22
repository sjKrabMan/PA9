#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "paddle.hpp"
//#include "gameObj.hpp"
#include "wall.hpp"
#include "map.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");
	

	Wall wall1(sf::Vector2f(20, 200), sf::Vector2f(0, 0), sf::Color::Cyan);
	Wall wall2(sf::Vector2f(20, 200), sf::Vector2f(500, 500), sf::Color::Red);

	Map map1(sf::Vector2f(1000, 1000));


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

	

		// Ethan is here



		window.clear();
		window.draw(wall1);
		window.draw(wall2);
		map1.draw(window);
		window.display();

	}

	return 0;
}