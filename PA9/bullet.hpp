
#include <SFML/Graphics.hpp>
#include <iostream>


class Bullet : public sf::CircleShape
{
public:
	Bullet(double radius, sf::Vector2f pos, sf::Color color) : sf::CircleShape(radius)
	{
		this->setRadius(radius);
		this->setPosition(pos);
		this->setFillColor(color);

	}

	~Bullet() {};

	// checks for collision with wall
	void WallCollision(sf::RectangleShape wall)
	{
		float wallRightBounds = wall.getGlobalBounds().left + wall.getGlobalBounds().width;
		float wallBottomBounds = wall.getGlobalBounds().top + wall.getGlobalBounds().height;

		float ballRightBounds = this->getGlobalBounds().left + this->getGlobalBounds().width;
		float ballBottomBounds = this->getGlobalBounds().top + this->getGlobalBounds().height;

		// handles ball collision with left wall
		if (this->getGlobalBounds().left >= wallRightBounds)
		{
			mXDir *= -1;
		}

		// handles ball collision with right wall
		if (ballRightBounds <= wall.getGlobalBounds().left)
		{
			mXDir *= -1;
		}

		// handles ball collision with top wall
		if (this->getGlobalBounds().top >= wallBottomBounds)
		{
			mYDir *= -1;
		}

		// handles ball collision with bottom wall
		if (ballBottomBounds <= wall.getGlobalBounds().top)
		{
			mYDir *= -1;
		}
	}

	// set posistion, direction, and speed of ball  ** EXPERIMENTAL **
	// add a bullet-wall collision check in main before calling this function
	void setShot(sf::ConvexShape tank)
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (tank.getRotation() == 0.f)
			{
				this ->setPosition(tank.getPosition().x + 50, tank.getPosition().y);
				this->move(0, -1);

			}
			else if (tank.getRotation() == 90.f)
			{
				this->setPosition(tank.getPosition().x, tank.getPosition().y + 50);
				this->move(1, 0);
			}
			else if (tank.getRotation() == 180.f)
			{
				this->setPosition(tank.getPosition().x - 50, tank.getPosition().y);
				this->move(0, 1);
			}
			else if (tank.getRotation() == 270.f)
			{
				this->setPosition(tank.getPosition().x, tank.getPosition().y - 50);
				this->move(-1, 0);
			}
			else if (tank.getRotation() == 45.f)
			{
				this->setPosition(tank.getOrigin().x + 50, tank.getOrigin().y + 50);
				this->move(1, -1);
			}
			else if (tank.getRotation() == 135.f)
			{
				this->setPosition(tank.getOrigin().x - 50, tank.getOrigin().y + 50);
				this->move(1, 1);
			}
			else if (tank.getRotation() == 225.f)
			{
				this->setPosition(tank.getOrigin().x - 50, tank.getOrigin().y - 50);
				this->move(-1, 1);
			}
			else if (tank.getRotation() == 315.f)
			{
				this->setPosition(tank.getOrigin().x + 50, tank.getOrigin().y - 50);
				this->move(-1, -1);
			}

			inPlay = true;
		}
		
	}


	int getXDir()
	{
		return mXDir;
	}

	int getYDir()
	{
		return mYDir;
	}


private:

	int mXDir = 1;
	int mYDir = 1;


	
	bool inPlay = false;

};