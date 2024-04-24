#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "paddle.hpp"
//#include "gameObj.hpp"
//#include "wall.hpp"
//#include "map.hpp"
//#include "tank.hpp"
#include "Menu.h"
#include "testing.hpp"

int main()
{
	
    Menu menu;
    testing test;
    int option = 0;


    do
    {
        menu.displaymenu();
        option = menu.grabChoice();
        switch (option)
        {
        case 1:
            menu.displayInstructuions();
            break;
        case 3:
            test.test_move();


            break;
        case 4:
            return 0;
        }
        


    } while (option != 2);
   
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");


	Wall wall1(sf::Vector2f(10, 100), sf::Vector2f(0, 0), sf::Color::Cyan);
	Wall wall2(sf::Vector2f(10, 100), sf::Vector2f(500, 500), sf::Color::Red);

	Tank p1tank(sf::Vector2f(200, 100), sf::Color::Green);
	Tank p2tank(sf::Vector2f(740, 740), sf::Color::White);

    Bullet p1Bullet(15, sf::Vector2f(-10, -10), sf::Color::Green);
    Bullet p2Bullet(15, sf::Vector2f(-10, -10), sf::Color::White);


    int p1CurrentBullet = 3;
    int p2CurrentBullet = 3;

	//Map map1(sf::Vector2f(1000, 1000));

    Map map1(sf::Vector2f(1000, 1000));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }



        // collision check member functions for tank player 1
        p1tank.p1Collision(wall1);
        p1tank.p1Collision(wall2);
        
        // collision check member functions for tank player 2
        p2tank.p2Collision(wall1);
        p2tank.p2Collision(wall2);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			p1Bullet.p1setShot(p1tank);
		}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
			p2Bullet.p2setShot(p2tank);
		}

        p1Bullet.WallCollision(wall1);
        p1Bullet.WallCollision(wall2);
        p1Bullet.moveBullet();

        p2Bullet.WallCollision(wall1);
        p2Bullet.WallCollision(wall2);
        p2Bullet.moveBullet();
        


        // p1 tank movement
        p1tank.p1Movement();

        
        
        // p2 tank movement
        p2tank.p2Movement();
        

		window.clear();
		window.draw(wall1);
		window.draw(wall2);

		window.draw(p1tank);
		window.draw(p2tank);
		window.draw(p1Bullet);
        window.draw(p2Bullet);

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