#include <SFML/Graphics.hpp>
#include "gameObj.hpp"
#include "wall.hpp"

class Map : public GameObj {

public:
	//creates wall objects around perimeter of map
	void loadMap(const sf::Vector2f& mapSize) {
		//consider declare mapsize const in main
		float wallThickness = 50.0f;
		walls.push_back(Wall(sf::Vector2f(mapSize.x, wallThickness), sf::Vector2f(0.0, 0.0))); //topwall 
		walls.push_back(Wall(sf::Vector2f(mapSize.x, wallThickness), sf::Vector2f(0, mapSize.y - wallThickness))); //botwall
		walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(0.0, 0.0))); //leftwall
		walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(mapSize.x - wallThickness, 0))); //rightwall
	}

	void draw(sf::RenderWindow& window) {
		for (auto& wall : walls) {
			wall.draw(window);
		}
	}

private:
	std::vector<Wall> walls;

};

