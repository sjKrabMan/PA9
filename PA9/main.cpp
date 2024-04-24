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

	Tank p1tank(sf::Vector2f(100, 100), sf::Color::Green);
	Tank p2tank(sf::Vector2f(900, 900), sf::Color::White);

    Bullet p1Bullet(15, sf::Vector2f(-10, -10), sf::Color::Green);



    Bullet p2Bullet(15, sf::Vector2f(-10, -10), sf::Color::White);

    int p1Lives = 3;
    int p2Lives = 3;

    Map gameMap(sf::Vector2f(1000, 1000));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }      



       
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
        

        for (int i = 0; i < gameMap.walls.size(); ++i) {
            // collision check member functions for tank & bullet player 1
            p1tank.p1Collision(gameMap.walls[i]);
            p1Bullet.WallCollision(gameMap.walls[i]);

            // collision check member functions for tank & bullet player 2
            p2tank.p2Collision(gameMap.walls[i]);
            p2Bullet.WallCollision(gameMap.walls[i]);
        }      
        

        // p1 tank movement
        p1tank.p1Movement();

        // p2 tank movement
        p2tank.p2Movement();
        
         window.clear();


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
    gameMap.draw(window);
		window.display();

        

        if (p1Lives == 0 || p2Lives == 0)
        {
            window.close();
        }

        if (p1Lives == 0 || p2Lives == 0)
        {
            window.close();
        }

        if (p2Lives == 0)
        {
            std::cout << R"(
 _______   __                                                 ______                             __       __  __                      __ 
/       \ /  |                                               /      \                           /  |  _  /  |/  |                    /  |
$$$$$$$  |$$ |  ______   __    __   ______    ______        /$$$$$$  | _______    ______        $$ | / \ $$ |$$/  _______    _______ $$ |
$$ |__$$ |$$ | /      \ /  |  /  | /      \  /      \       $$ |  $$ |/       \  /      \       $$ |/$  \$$ |/  |/       \  /       |$$ |
$$    $$/ $$ | $$$$$$  |$$ |  $$ |/$$$$$$  |/$$$$$$  |      $$ |  $$ |$$$$$$$  |/$$$$$$  |      $$ /$$$  $$ |$$ |$$$$$$$  |/$$$$$$$/ $$ |
$$$$$$$/  $$ | /    $$ |$$ |  $$ |$$    $$ |$$ |  $$/       $$ |  $$ |$$ |  $$ |$$    $$ |      $$ $$/$$ $$ |$$ |$$ |  $$ |$$      \ $$/ 
$$ |      $$ |/$$$$$$$ |$$ \__$$ |$$$$$$$$/ $$ |            $$ \__$$ |$$ |  $$ |$$$$$$$$/       $$$$/  $$$$ |$$ |$$ |  $$ | $$$$$$  | __ 
$$ |      $$ |$$    $$ |$$    $$ |$$       |$$ |            $$    $$/ $$ |  $$ |$$       |      $$$/    $$$ |$$ |$$ |  $$ |/     $$/ /  |
$$/       $$/  $$$$$$$/  $$$$$$$ | $$$$$$$/ $$/              $$$$$$/  $$/   $$/  $$$$$$$/       $$/      $$/ $$/ $$/   $$/ $$$$$$$/  $$/ 
                        /  \__$$ |                                                                                                       
                        $$    $$/                                                                                                        
                         $$$$$$/                                                                                                         )";
        }

        if (p1Lives == 0)
        {
            std::cout << R"(
 _______   __                                                ________                              __       __  __                      __ 
/       \ /  |                                              /        |                            /  |  _  /  |/  |                    /  |
$$$$$$$  |$$ |  ______   __    __   ______    ______        $$$$$$$$/__   __   __   ______        $$ | / \ $$ |$$/  _______    _______ $$ |
$$ |__$$ |$$ | /      \ /  |  /  | /      \  /      \          $$ | /  | /  | /  | /      \       $$ |/$  \$$ |/  |/       \  /       |$$ |
$$    $$/ $$ | $$$$$$  |$$ |  $$ |/$$$$$$  |/$$$$$$  |         $$ | $$ | $$ | $$ |/$$$$$$  |      $$ /$$$  $$ |$$ |$$$$$$$  |/$$$$$$$/ $$ |
$$$$$$$/  $$ | /    $$ |$$ |  $$ |$$    $$ |$$ |  $$/          $$ | $$ | $$ | $$ |$$ |  $$ |      $$ $$/$$ $$ |$$ |$$ |  $$ |$$      \ $$/ 
$$ |      $$ |/$$$$$$$ |$$ \__$$ |$$$$$$$$/ $$ |               $$ | $$ \_$$ \_$$ |$$ \__$$ |      $$$$/  $$$$ |$$ |$$ |  $$ | $$$$$$  | __ 
$$ |      $$ |$$    $$ |$$    $$ |$$       |$$ |               $$ | $$   $$   $$/ $$    $$/       $$$/    $$$ |$$ |$$ |  $$ |/     $$/ /  |
$$/       $$/  $$$$$$$/  $$$$$$$ | $$$$$$$/ $$/                $$/   $$$$$/$$$$/   $$$$$$/        $$/      $$/ $$/ $$/   $$/ $$$$$$$/  $$/ 
                        /  \__$$ |                                                                                                         
                        $$    $$/                                                                                                          
                         $$$$$$/                                                                                                           )";
        }

    }
        
	

	return 0;
}