#pragma once

#include <SFML/Graphics.hpp>


class Ball : public sf::CircleShape {
public:
	Ball(float radius, const sf::Vector2f& pos,
		const sf::Color color) : sf::CircleShape(radius)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}
private:

};