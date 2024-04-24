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

	Wall wall1(sf::Vector2f(50, 100), sf::Vector2f(1500, 0), sf::Color::Cyan);
	Wall wall2(sf::Vector2f(50, 100), sf::Vector2f(500, 500), sf::Color::Red);

    Wall topBound(sf::Vector2f(1000, 10), sf::Vector2f(0, 0), sf::Color::Transparent);
    Wall bottomBound(sf::Vector2f(1000, 10), sf::Vector2f(0, 990), sf::Color::Transparent);
    Wall leftBound(sf::Vector2f(10, 1000), sf::Vector2f(0, 0), sf::Color::Transparent);
    Wall rightBound(sf::Vector2f(10, 1000), sf::Vector2f(990, 0), sf::Color::Transparent);

	Tank p1tank(sf::Vector2f(200, 100), sf::Color::Green);
	Tank p2tank(sf::Vector2f(740, 740), sf::Color::White);

    Bullet p1Bullet(15, sf::Vector2f(-10, -10), sf::Color::Green);


    Bullet p2Bullet(15, sf::Vector2f(-10, -10), sf::Color::White);

    int p1Lives = 3;
    int p2Lives = 3;
    
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
        p1tank.p1Collision(topBound);
        p1tank.p1Collision(bottomBound);
        p1tank.p1Collision(leftBound);
        p1tank.p1Collision(rightBound);
        
        // collision check member functions for tank player 2
        p2tank.p2Collision(wall1);
        p2tank.p2Collision(wall2);
        p2tank.p2Collision(topBound);
        p2tank.p2Collision(bottomBound);
        p2tank.p2Collision(leftBound);
        p2tank.p2Collision(rightBound);

       
        // set up shots based on current bullet
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !p1Bullet.getInPlay())
        {
            p1Bullet.p1setShot(p1tank);
		}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !p2Bullet.getInPlay())
        {
            p2Bullet.p2setShot(p2tank);
           
        }

       

        

        // move bullets if they are in play
        if (p1Bullet.getInPlay() == true)
        {
			p1Bullet.moveBullet();
		}

        if (p2Bullet.getInPlay() == true)
        {
            p2Bullet.moveBullet();
        }


        // p1bullet collision check
        p1Bullet.WallCollision(wall1);
        p1Bullet.WallCollision(wall2);
        p1Bullet.WallCollision(topBound);
        p1Bullet.WallCollision(bottomBound);
        p1Bullet.WallCollision(leftBound);
        p1Bullet.WallCollision(rightBound);



        // p2bullet1 collision check
        p2Bullet.WallCollision(wall1);
        p2Bullet.WallCollision(wall2);
        p2Bullet.WallCollision(topBound);
        p2Bullet.WallCollision(bottomBound);
        p2Bullet.WallCollision(leftBound);
        p2Bullet.WallCollision(rightBound);
    

        if (p1Bullet.getGlobalBounds().intersects(p2tank.getGlobalBounds()))
        {

            p1Bullet.setPosition(-10, -10);
            p2Bullet.setPosition(-10, -10);
            p1Bullet.setInPlay(false);
            p2Bullet.setInPlay(false);
            p1tank.setPosition(100, 100);
            p2tank.setPosition(900, 900);
            

            p2Lives--;
          
        }

        if (p2Bullet.getGlobalBounds().intersects(p1tank.getGlobalBounds()))
        {
            p1Bullet.setPosition(-10, -10);
            p2Bullet.setPosition(-10, -10);
            p1Bullet.setInPlay(false);
            p2Bullet.setInPlay(false);
            p1tank.setPosition(100, 100);
            p2tank.setPosition(900, 900);
            

            p1Lives--;
            
        }


        // p1 tank movement
        p1tank.p1Movement();
        
        // p2 tank movement
        p2tank.p2Movement();
        

		window.clear();
		window.draw(wall1);
		window.draw(wall2);

		

        if (p1Bullet.getRicochetLimit() > 0 && p1Bullet.getInPlay())
        {
			window.draw(p1Bullet);
		}
        else
        {
			p1Bullet.setInPlay(false);
            p1Bullet.setRicochetLimit(3);
		}

        if (p2Bullet.getRicochetLimit() > 0 && p2Bullet.getInPlay())
        {
			window.draw(p2Bullet);
		}
        else
        {
			p2Bullet.setInPlay(false);
			p2Bullet.setRicochetLimit(3);
        }

        window.draw(p1tank);
        window.draw(p2tank);

		window.draw(topBound);
		window.draw(bottomBound);
		window.draw(leftBound);
		window.draw(rightBound);
        
	    
		window.display();

        if (p1Lives == 0 || p2Lives == 0)
        {
            window.close();
        }
        
	}

	return 0;
}