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
	

	Wall wall1(sf::Vector2f(20, 200), sf::Vector2f(0, 0), sf::Color::Cyan);
	Wall wall2(sf::Vector2f(20, 200), sf::Vector2f(500, 500), sf::Color::Red);

	Tank p1tank(sf::Vector2f(200, 100), sf::Color::Green);

	//Tank p2tank(sf::Vector2f(40, 40), sf::Vector2f(840, 840), sf::Color::Yellow);

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



        ///////////////this is all the movement used for tank player 1//////////////////////////////////////////
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            p1tank.move(0, -0.05);
            p1tank.setRotation(270.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            p1tank.move(0, 0.05);
            p1tank.setRotation(90.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            p1tank.move(0.05, 0);
            p1tank.setRotation(0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            p1tank.move(-0.05, 0);
            p1tank.setRotation(180.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            p1tank.setRotation(315.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            p1tank.setRotation(225.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            p1tank.setRotation(135.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            p1tank.setRotation(45.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            p1tank.setRotation(90.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            p1tank.setRotation(270.f);
        }
        ///////////////this it the collision detection for tank player 1//////////////////////////////////////
        if (p1tank.getGlobalBounds().intersects(wall1.getGlobalBounds()))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                p1tank.move(0, 0.05);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                p1tank.move(0, -0.05);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                p1tank.move(-0.05, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                p1tank.move(0.05, 0);
            }
        }

        if (p1tank.getGlobalBounds().intersects(wall2.getGlobalBounds()))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                p1tank.move(0, 0.05);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                p1tank.move(0, -0.05);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                p1tank.move(-0.05, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                p1tank.move(0.05, 0);
            }
        }
    





		// Ethan is here



		window.clear();
		window.draw(wall1);
		window.draw(wall2);
		//wall1.draw(window);
		/*wall2.draw(window);
		map1.draw(window);*/

		window.draw(p1tank);
		//window.draw(p2tank);

		window.display();


		//std::cout << "s" << std::endl; // leeevi boom
		//std::cout << "3" << std::endl;
	}

	return 0;
}