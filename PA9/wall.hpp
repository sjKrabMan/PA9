#pragma once
#include <SFML/Graphics.hpp>
#include "gameObj.hpp"


class Wall : public GameObj {
public:

	//constructor to generate a wall of specified size and position (currently only rectangles)
	Wall(sf::Vector2f dimensions, sf::Vector2f position) : GameObj() {
		shape.setSize(dimensions);
		shape.setPosition(position);
		shape.setFillColor(sf::Color::Blue);
	}

	virtual void draw(sf::RenderWindow& window) override {
		window.draw(shape);
	}

	virtual void update(const sf::Time& dt) override {
		//wall wont update. 90% sure I still needed to define this func tho to prevent compile issues.
	}

};