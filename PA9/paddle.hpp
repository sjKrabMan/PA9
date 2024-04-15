#pragma once

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape {
public:
	Paddle(const sf::Vector2f& size, const sf::Vector2f& pos,
		const sf::Color& color) : sf::RectangleShape(size)
	{ //vector2f is a 2 param vector of floats
		this->setPosition(pos);
		this->setFillColor(color);
	}

private:

};