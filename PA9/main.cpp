#include <SFML/Graphics.hpp>

#include "ball.hpp"
#include "paddle.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");
	sf::CircleShape shape(100.f);

	Ball gameBall(50.0, sf::Vector2f(200, 200), sf::Color::Red);

	Paddle p1paddle(sf::Vector2f(20, 200), sf::Vector2f(0, 0), sf::Color::Green),
		p2paddle(sf::Vector2f(20, 200), sf::Vector2f(980, 0), sf::Color::Green);

	int direction = 1, ballDirection = 1;

	//shape.setFillColor(sf::Color::Green);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		gameBall.move(.4 * ballDirection, 0);

		if (p2paddle.getGlobalBounds().intersects(gameBall.getGlobalBounds())) {
			ballDirection *= -1;
		}

		//p1 paddle up/down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			//not case sensitive
			p1paddle.move(0, 1 * direction);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			p1paddle.move(0, 1 * -(direction));
		}
		//p2 paddle up/down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			p2paddle.move(0, 1 * direction);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			p2paddle.move(0, 1 * -(direction));
		}

		window.clear();
		//window.draw(shape);
		window.draw(gameBall);
		window.draw(p1paddle);
		window.draw(p2paddle);
		window.display();
	}

	return 0;
}