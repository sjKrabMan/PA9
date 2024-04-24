#include <SFML/Graphics.hpp>
#include <iostream>
#include "gameObj.hpp"
#include <vector>
#include "bullet.hpp"

using std::vector;

class Tank : public sf::ConvexShape
{
public:
	Tank(const sf::Vector2f& pos, const sf::Color& color) : sf::ConvexShape()
	{
        /*tank = object();*/
		/*tank.setPosition(pos);
		tank.setFillColor(color);*/
        setShape(pos,color);
		
	}

    void setShape(const sf::Vector2f& pos, const sf::Color& color)
    {
        this->setPointCount(20);
        setPoint(0, sf::Vector2f(0, 900));
        setPoint(1, sf::Vector2f(100, 900));
        setPoint(2, sf::Vector2f(100, 920));
        setPoint(3, sf::Vector2f(80, 920));
        setPoint(4, sf::Vector2f(80, 940));
        setPoint(5, sf::Vector2f(100, 940));
        setPoint(6, sf::Vector2f(100, 930));
        setPoint(7, sf::Vector2f(120, 930));
        setPoint(8, sf::Vector2f(120, 970));
        setPoint(9, sf::Vector2f(100, 970));
        setPoint(10, sf::Vector2f(100, 960));
        setPoint(11, sf::Vector2f(80, 960));
        setPoint(12, sf::Vector2f(80, 980));
        setPoint(13, sf::Vector2f(100, 980));
        setPoint(14, sf::Vector2f(100, 1000));
        setPoint(15, sf::Vector2f(0, 1000));
        setPoint(16, sf::Vector2f(0, 980));
        setPoint(17, sf::Vector2f(20, 980));
        setPoint(18, sf::Vector2f(20, 920));
        setPoint(19, sf::Vector2f(0, 920));
        setOrigin(50, 950);
        setFillColor(color);
        setPosition(pos);
        setScale(0.5, 0.5);
    }

  

    ~Tank() {};

	//virtual void draw(sf::RenderWindow& window) override {
	//	//get_shape();
	//	//window.draw(window);
	//}

	virtual void update(const sf::Time& dt) {
		//wall wont update. 90% sure I still needed to define this func tho to prevent compile issues.
	}

	/*sf::RectangleShape get_shape()
	{
		return this->shape;
	}*/


    void p1Movement()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            move(0, -0.1);
            setRotation(270.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            move(0, 0.1);
            setRotation(90.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            move(0.1, 0);
            setRotation(0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            move(-0.1, 0);
            setRotation(180.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            setRotation(315.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            setRotation(225.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            setRotation(135.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            setRotation(45.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            setRotation(90.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            setRotation(270.f);
        }
    }

    void p2Movement()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            move(0, -0.1);
            setRotation(270.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            move(0, 0.1);
            setRotation(90.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            move(0.1, 0);
            setRotation(0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            move(-0.1, 0);
            setRotation(180.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            setRotation(315.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            setRotation(225.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            setRotation(135.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            setRotation(45.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
           setRotation(90.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            setRotation(270.f);
        }
    }


    void p1Collision(sf::RectangleShape wall)
    {
        if (getGlobalBounds().intersects(wall.getGlobalBounds()))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                move(0, 0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                move(0, -0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                move(-0.1, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                move(0.1, 0);
            }
        }

        
        
    }

    void p2Collision(sf::RectangleShape wall)
    {
        if (getGlobalBounds().intersects(wall.getGlobalBounds()))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                move(0, 0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                move(0, -0.1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                move(-0.1, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                move(0.1, 0);
            }
        }
    }



private:



};




