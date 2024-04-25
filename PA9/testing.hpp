#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"
#include "tank.hpp"

class testing
{
public:

	bool test_move()
	{
		
		sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");

		Tank tank(sf::Vector2f(200, 100), sf::Color::Green);


		int count = 0;

		Map map1(sf::Vector2f(1000, 1000));

		sf::Vector2f start = tank.getPosition();
		sf::Vector2f check;



		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			tank.p1Movement();

			check = tank.getPosition();

			if (start != check)
			{
				count++;
				if (count == 900)
				{
					window.close();
					return true;
				}
			}

			window.clear();

			window.draw(tank);

			window.display();
		}
	}

	bool test_rotate()
	{
		sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");

		Tank tank(sf::Vector2f(200, 100), sf::Color::Green);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			tank.p1Movement();


			window.clear();

			window.draw(tank);

			window.display();

		}
	}

	bool test_shoot();

	bool test_ricochet();

	bool test_kill();
};
