#include <SFML/Graphics.hpp>
#include "gameObj.hpp"
#include "wall.hpp"

class Map : public GameObj {

public:
	//creates wall objects around perimeter of map
	Map(const sf::Vector2f& mapSize) {
		loadMap(mapSize);
	}

	void loadMap(const sf::Vector2f& mapSize) {
		//consider declare mapsize const in main
		float wallThickness = 0.01f;
		walls.push_back(Wall(sf::Vector2f(mapSize.x, wallThickness), sf::Vector2f(0.0, 0.0))); //topwall 
		walls.push_back(Wall(sf::Vector2f(mapSize.x, wallThickness), sf::Vector2f(0, mapSize.y - wallThickness))); //botwall
		walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(0.0, 0.0))); //leftwall
		walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(mapSize.x - wallThickness, 0))); //rightwall

		//obstacles
		walls.push_back(Wall(sf::Vector2f(20, 20), sf::Vector2f(10, 10)));
		walls.push_back(Wall(sf::Vector2f(20, 20), sf::Vector2f(250, 100)));
		walls.push_back(Wall(sf::Vector2f(20, 20), sf::Vector2f(300, 150)));
		walls.push_back(Wall(sf::Vector2f(20, 20), sf::Vector2f(900, 500)));

	}

	void draw(sf::RenderWindow& window) {
		for (auto& wall : walls) {
			wall.draw(window);
		}
	}

	virtual void update(const sf::Time& dt) override {
		//wall wont update. 90% sure I still needed to define this func tho to prevent compile issues.
	}

private:
	std::vector<Wall> walls;

};

