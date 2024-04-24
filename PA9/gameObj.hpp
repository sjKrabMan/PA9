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


	//meant to be overridden by other derived classes if needed
	virtual void update(const sf::Time& dt) = 0;

};