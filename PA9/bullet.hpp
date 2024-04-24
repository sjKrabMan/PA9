
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

		ricochetLimit = 4;
		mXDir = 1;
		mYDir = 1;
		mXSpeed = 0;
		mYSpeed = 0;

	}


	// checks for collision with bullet-wall
	void WallCollision(sf::RectangleShape wall)
	{
		

		double BufferZone = 10;

		// Calculate bounds of the wall
		double wallRightBounds = wall.getPosition().x + wall.getSize().x;
		double wallBottomBounds = wall.getPosition().y + wall.getSize().y;

		// Calculate bounds of the bullet
		double ballRightBounds = this->getPosition().x + this->getRadius();
		double ballBottomBounds = this->getPosition().y + this->getRadius();

		if (this->getGlobalBounds().intersects(wall.getGlobalBounds()))
		{
			// ball hits wall from left or right
			if ((ballRightBounds > wall.getGlobalBounds().left - BufferZone &&
				this->getGlobalBounds().left < wall.getGlobalBounds().left) ||
				(this->getGlobalBounds().left < wallRightBounds + BufferZone &&
					ballRightBounds > wallRightBounds))
			{
				mXDir *= -1;
				ricochetLimit--;
			}

			// ball hits wall from the top or bottom
			if ((ballBottomBounds > wall.getGlobalBounds().top - BufferZone &&
				this->getGlobalBounds().top < wall.getGlobalBounds().top) ||
				(this->getGlobalBounds().top < wallBottomBounds + BufferZone &&
					ballBottomBounds > wallBottomBounds))
			{
				mYDir = -1;
				ricochetLimit--;
			}

		}

	}

	// set posistion, direction, and speed of ball  ** EXPERIMENTAL **
	// add a bullet-wall collision check in main before calling this function
	void p1setShot(sf::ConvexShape& tank)
	{
		
		
			if (tank.getRotation() == 0.f)
			{
				this ->setPosition(tank.getPosition().x + 70, tank.getPosition().y - 15);
				mXSpeed = .3;
				mYSpeed = 0;

				mXDir = 1;
				mYDir = 1;

			}
			else if (tank.getRotation() == 90.f)
			{
				this->setPosition(tank.getPosition().x - 15, tank.getPosition().y + 70);
				mXSpeed = 0;
				mYSpeed = .3;

				mXDir = 1;
				mYDir = 1;
			}
			else if (tank.getRotation() == 180.f)
			{
				this->setPosition(tank.getPosition().x - 100, tank.getPosition().y - 15);
				mXSpeed = -.3;
				mYSpeed = 0;

				mXDir = 1;
				mYDir = 1;
			}
			else if (tank.getRotation() == 270.f)
			{
				this->setPosition(tank.getPosition().x - 15, tank.getPosition().y - 100);
				mXSpeed = 0;
				mYSpeed = -.3;

				mXDir = 1;
				mYDir = 1;
			}
			else if (tank.getRotation() == 45.f)
			{
				this->setPosition(tank.getPosition().x + 45, tank.getPosition().y + 45);
				mXSpeed = .3;
				mYSpeed = .3;

				mXDir = 1;
				mYDir = 1;
			}
			else if (tank.getRotation() == 135.f)
			{
				this->setPosition(tank.getPosition().x - 75, tank.getPosition().y + 45);
				mXSpeed = -.3;
				mYSpeed = .3;

				mXDir = 1;
				mYDir = 1;
			}
			else if (tank.getRotation() == 225.f)
			{
				this->setPosition(tank.getPosition().x - 75, tank.getPosition().y - 75);
				mXSpeed = -.3;
				mYSpeed = -.3;

				mXDir = 1;
				mYDir = 1;
			}
			else if (tank.getRotation() == 315.f)
			{
				this->setPosition(tank.getPosition().x + 45, tank.getPosition().y - 75);
				mXSpeed = .3;
				mYSpeed = -.3;

				mXDir = 1;
				mYDir = 1;
			}

			inPlay = true;
		
		
	}

	void p2setShot(sf::ConvexShape& tank)
	{
		if (tank.getRotation() == 0.f)
		{
			this->setPosition(tank.getPosition().x + 70, tank.getPosition().y - 15);
			mXSpeed = .3;
			mYSpeed = 0;

			mXDir = 1;
			mYDir = 1;

		}
		else if (tank.getRotation() == 90.f)
		{
			this->setPosition(tank.getPosition().x - 15, tank.getPosition().y + 70);
			mXSpeed = 0;
			mYSpeed = .3;

			mXDir = 1;
			mYDir = 1;
		}
		else if (tank.getRotation() == 180.f)
		{
			this->setPosition(tank.getPosition().x - 100, tank.getPosition().y - 15);
			mXSpeed = -.3;
			mYSpeed = 0;

			mXDir = 1;
			mYDir = 1;
		}
		else if (tank.getRotation() == 270.f)
		{
			this->setPosition(tank.getPosition().x - 15, tank.getPosition().y - 100);
			mXSpeed = 0;
			mYSpeed = -.3;

			mXDir = 1;
			mYDir = 1;
		}
		else if (tank.getRotation() == 45.f)
		{
			this->setPosition(tank.getPosition().x + 45, tank.getPosition().y + 45);
			mXSpeed = .3;
			mYSpeed = .3;

			mXDir = 1;
			mYDir = 1;
		}
		else if (tank.getRotation() == 135.f)
		{
			this->setPosition(tank.getPosition().x - 75, tank.getPosition().y + 45);
			mXSpeed = -.3;
			mYSpeed = .3;

			mXDir = 1;
			mYDir = 1;
		}
		else if (tank.getRotation() == 225.f)
		{
			this->setPosition(tank.getPosition().x - 75, tank.getPosition().y - 75);
			mXSpeed = -.3;
			mYSpeed = -.3;

			mXDir = 1;
			mYDir = 1;
		}
		else if (tank.getRotation() == 315.f)
		{
			this->setPosition(tank.getPosition().x + 45, tank.getPosition().y - 75);
			mXSpeed = .3;
			mYSpeed = -.3;

			mXDir = 1;
			mYDir = 1;
		}

		inPlay = true;
	}

	bool getInPlay()
	{
		return inPlay;
	}
	void setInPlay(bool play)
	{
		inPlay = play;
	}

	void moveBullet()
	{
		this->move(mXSpeed * mXDir, mYSpeed * mYDir);
	}

	int getXDir()
	{
		return mXDir;
	}

	int getYDir()
	{
		return mYDir;
	}

	double getXSpeed()
	{
		return mXSpeed;
	}

	double getYSpeed()
	{
		return mYSpeed;
	}

	int getRicochetLimit()
	{
		return ricochetLimit;
	}
	void setRicochetLimit(int limit)
	{
		ricochetLimit = limit;
	}


private:

	int ricochetLimit;
	int mXDir;
	int mYDir;
	double mXSpeed;
	double mYSpeed;

	
	bool inPlay = false;

};