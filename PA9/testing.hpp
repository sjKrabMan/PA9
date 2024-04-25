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

			if (((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) || ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
				|| ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) || ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
			{
				if (check != start)
				{
					count++;
					if (count == 200)
					{
						window.close();
						return true;
					}
				}

			}
			check = tank.getPosition();

			window.clear();

			window.draw(tank);

			window.display();

		}
	}

	bool test_shoot()
	{
		sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");

		Tank tank(sf::Vector2f(200, 100), sf::Color::Green);

		Bullet bullet(15, sf::Vector2f(-10, -10), sf::Color::Green);

		Map map1(sf::Vector2f(1000, 1000));

		sf::Vector2f start = bullet.getPosition();
		sf::Vector2f check;

		int count = 0;

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			tank.p1Movement();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				bullet.p1setShot(tank);


			}

			check = bullet.getPosition();

			if (start != check)
			{
				count++;
				if (count == 500) { window.close(); return true; }
			}

			bullet.moveBullet();

			window.clear();

			window.draw(tank);
			window.draw(bullet);


			window.display();

		}
		return true;
	}

	bool test_ricochet()
	{
		sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");

		Tank tank(sf::Vector2f(200, 100), sf::Color::Green);

		Bullet bullet(15, sf::Vector2f(-10, -10), sf::Color::Green);

		Map map1(sf::Vector2f(1000, 1000));

		Map gameMap(sf::Vector2f(1000, 1000));

		int count = 0;

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !bullet.getInPlay())
			{
				bullet.p1setShot(tank);

			}

			if (bullet.getInPlay() == true)
			{
				bullet.moveBullet();
			}
			
			for (int i = 0; i < gameMap.walls.size(); ++i) {
				// collision check member functions for tank & bullet player 1
				tank.p1Collision(gameMap.walls[i]);
				bullet.WallCollision(gameMap.walls[i]);
				
			}

			if (bullet.getRicochetLimit() > 0 && bullet.getInPlay())
			{
				window.draw(bullet);
			}
			else
			{
				bullet.setInPlay(false);
				bullet.setRicochetLimit(3);
				
			}

			if (bullet.getRicochetLimit() == 1)
			{
				window.close();
				return true;
			}

			window.clear();

			window.draw(tank);
			window.draw(bullet);

			window.display();
		}
		return true;

	}

	bool test_kill()
	{
		sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");

		Tank tank_1(sf::Vector2f(200, 100), sf::Color::Green);

		Tank tank_2(sf::Vector2f(900, 100), sf::Color::White);

		int count = 0;

		Map map1(sf::Vector2f(1000, 1000));

		
		Bullet bullet(15, sf::Vector2f(-10, -10), sf::Color::Green);


		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			tank_1.p1Movement();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !bullet.getInPlay())
			{
				bullet.p1setShot(tank_1);

			}

			if (bullet.getInPlay() == true)
			{
				bullet.moveBullet();
			}

			if (bullet.getGlobalBounds().intersects(tank_2.getGlobalBounds()))
			{
			bullet.setPosition(-10, -10);
			bullet.setInPlay(false);
			tank_1.setPosition(100, 100);
			tank_2.setPosition(100, 900);

			window.close();
			return true;
			}

			window.clear();

			window.draw(tank_1);

			window.draw(tank_2);

			window.draw(bullet);

			window.display();
		}
		
		
	}
};