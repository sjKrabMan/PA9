#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "paddle.hpp"
//#include "gameObj.hpp"
#include "wall.hpp"
#include "map.hpp"
#include "tank.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");
   
    //window.setFramerateLimit(30);

	//Wall wall1(sf::Vector2f(10, 100), sf::Vector2f(0, 0), sf::Color::Cyan);
	//Wall wall2(sf::Vector2f(10, 100), sf::Vector2f(500, 500), sf::Color::Red);

	Tank p1tank(sf::Vector2f(100, 100), sf::Color::Green);
	Tank p2tank(sf::Vector2f(900, 900), sf::Color::White);

    Bullet p1Bullet(15, sf::Vector2f(-10, -10), sf::Color::Green);
    Bullet p2Bullet(15, sf::Vector2f(-10, -10), sf::Color::White);

    int p1CurrentBullet = 3;
    int p2CurrentBullet = 3;


    Map gameMap(sf::Vector2f(1000, 1000));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }      

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			p1Bullet.p1setShot(p1tank);
		}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
			p2Bullet.p2setShot(p2tank);
		}

        for (int i = 0; i < gameMap.walls.size(); ++i) {
            // collision check member functions for tank & bullet player 1
            p1tank.p1Collision(gameMap.walls[i]);
            p1Bullet.WallCollision(gameMap.walls[i]);

            // collision check member functions for tank & bullet player 2
            p2tank.p2Collision(gameMap.walls[i]);
            p2Bullet.WallCollision(gameMap.walls[i]);
        }      
        
        // bullet movement tech
        p1Bullet.moveBullet();
        p2Bullet.moveBullet();

        // p1 tank movement
        p1tank.p1Movement();

        // p2 tank movement
        p2tank.p2Movement();
        

        window.clear();

		window.draw(p1tank);
		window.draw(p2tank);
		window.draw(p1Bullet);
        window.draw(p2Bullet);
        gameMap.draw(window);
		window.display();

       /* for (int i = 0; i < p1tank.getAmmo().size(); i++)
        {
            window.draw(p1tank.getAmmo()[i]);
        }

        for (int i = 0; i < p2tank.getAmmo().size(); i++)
        {
			window.draw(p2tank.getAmmo()[i]);
		}*/
	}

	return 0;
}