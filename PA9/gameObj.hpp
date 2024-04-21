#pragma once
#include <SFML/Graphics.hpp>


class GameObj : public sf::RectangleShape {

public:
	//this shape declaration can be replaced with sprite if we get those working
	sf::RectangleShape shape;
	
	//simple constructor: will need modded if we use sprites also
	GameObj() {
		shape.setSize(sf::Vector2f(50.0f, 50.0f));
		shape.setPosition(0, 0);
	}
	//lil virtual destructor action
	//not sure what defintion should look like but for now I think default destructor should work
	//virtual ~GameObj();


	//meant to be overridden by other derived classes if needed
	virtual void update(const sf::Time& dt) = 0;

	//makes shape on screen
	virtual void draw(sf::RenderWindow& display) {
		display.draw(shape);
	}
	//puts shape where it needs to go
	void setPosition(const sf::Vector2f& position) {
		shape.setPosition(position);
	}
	//returns shape pos
	sf::Vector2f getPosition() const {
		return shape.getPosition();
	}
};