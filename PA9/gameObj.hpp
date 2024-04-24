#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class GameObj : public sf::RectangleShape {

public:
	//this shape declaration can be replaced with sprite if we get those working
	//sf::RectangleShape shape;
	
	//simple constructor: will need modded if we use sprites also
	GameObj() : sf::RectangleShape(sf::Vector2f(0,0))
	{
		this->setPosition(sf::Vector2f(0, 0));
		this->setFillColor(sf::Color::Transparent);
	}

	GameObj(sf::Vector2f size, sf::Vector2f position, sf::Color color) : sf::RectangleShape(size)
	{
		this->setPosition(position);
		this->setFillColor(color);
	}
	//lil virtual destructor action
	//not sure what defintion should look like but for now I think default destructor should work
	//virtual ~GameObj();


	//meant to be overridden by other derived classes if needed
	virtual void update(const sf::Time& dt) = 0;

	//makes shape on screen
	//virtual void draw(sf::RenderWindow& display) {
	//	display.draw(shape);
	//}
	//puts shape where it needs to go
	/*void setPosition(const sf::Vector2f& position) {
		this->setPosition(position);
	}*/


	//returns shape pos
	/*sf::Vector2f getPosition() const {
		return shape.getPosition();
	}*/

	/*sf::Vector2f getShape(void) {
		return shape.getSize();
	}*/
};