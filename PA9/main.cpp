#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "paddle.hpp"
//#include "gameObj.hpp"
#include "wall.hpp"
#include "map.hpp"

//JP was here

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");
	//sf::CircleShape shape(100.f);

	Wall wall1(sf::Vector2f(20, 200), sf::Vector2f(0, 0));
	Wall wall2(sf::Vector2f(20, 200), sf::Vector2f(500, 500));

	Map map1(sf::Vector2f(1000, 1000));

	//Paddle p1paddle(sf::Vector2f(20, 200), sf::Vector2f(0, 0), sf::Color::Green);
		//p2paddle(sf::Vector2f(20, 200), sf::Vector2f(980, 0), sf::Color::Green);

	int direction = 1, ballDirection = 1;

	//shape.setFillColor(sf::Color::Green);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//gameBall.move(.4 * ballDirection, 0);

		//if (p2paddle.getGlobalBounds().intersects(gameBall.getGlobalBounds())) {
		//	ballDirection *= -1;
		//}

		////p1 paddle up/down
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		//	//not case sensitive
		//	p1paddle.move(0, 1 * direction);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		//	p1paddle.move(0, 1 * -(direction));
		//}
		////p2 paddle up/down
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		//	p2paddle.move(0, 1 * direction);
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		//	p2paddle.move(0, 1 * -(direction));
		//}




		//this happened pre pull request

		// peeep this shit boiiisss



		//dope ass comment


		window.clear();
		//window.draw(shape);
		//window.draw(gameBall);	
		//window.draw(p1paddle);
		//window.draw(p2paddle);

		//wall1.draw(window);
		wall2.draw(window);
		map1.draw(window);
		window.display();

		std::cout << "s" << std::endl; // leeevi boom
		std::cout << "3" << std::endl;
	}

	return 0;
}