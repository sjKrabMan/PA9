#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"
#include "paddle.hpp"
//#include "gameObj.hpp"
#include "wall.hpp"
#include "map.hpp"
#include "tank.hpp"

//JP was here
int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML workEvent(event)");
	

	Wall wall1(sf::Vector2f(20, 200), sf::Vector2f(0, 0), sf::Color::Cyan);
	Wall wall2(sf::Vector2f(20, 200), sf::Vector2f(500, 500), sf::Color::Red);

	Tank p1tank(sf::Vector2f(200, 100), sf::Color::Green);

	Tank p2tank(sf::Vector2f(740, 740), sf::Color::White);

	//Map map1(sf::Vector2f(1000, 1000));

Map map1(sf::Vector2f(1000, 1000));

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


        ///////////////this it the collision detection for tank player 1//////////////////////////////////////

        p1tank.p1Collision(wall1);

        p1tank.p1Collision(wall2);

        ///////////////this it the collision detection for tank player 2//////////////////////////////////////

        p2tank.p2Collision(wall1);

        p2tank.p2Collision(wall2);




        ///////////////this is all the movement used for tank player 1//////////////////////////////////////////
        

        p1tank.p1Movement();

        //////////////////////this is the movment for tank player 2////////////////////////
       /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            p2tank.move(0, -0.05);
            p2tank.setRotation(270.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            p2tank.move(0, 0.05);
            p2tank.setRotation(90.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p2tank.move(0.05, 0);
            p2tank.setRotation(0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p2tank.move(-0.05, 0);
            p2tank.setRotation(180.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p2tank.setRotation(315.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p2tank.setRotation(225.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p2tank.setRotation(135.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p2tank.setRotation(45.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p2tank.setRotation(90.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p2tank.setRotation(270.f);
        }*/

        p2tank.p2Movement();
    

        ////////////////////////////////////////////////////////


		window.clear();
		window.draw(wall1);
		window.draw(wall2);

		window.draw(p1tank);
		window.draw(p2tank);

		window.display();


	}

	return 0;
}