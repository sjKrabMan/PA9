#pragma once
#include <SFML/Graphics.hpp>
#include "gameObj.hpp"


class Wall : public GameObj {
public:

	//constructor to generate a wall of specified size and position (currently only rectangles)
	Wall(sf::Vector2f size, sf::Vector2f position, sf::Color color) : GameObj(size, position, color) {}


	virtual void update(const sf::Time& dt) override {
		//wall wont update. 90% sure I still needed to define this func tho to prevent compile issues.
	}

};