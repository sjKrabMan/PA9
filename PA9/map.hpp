#include <SFML/Graphics.hpp>
#include "gameObj.hpp"
#include "wall.hpp"

class Map : public GameObj {

public:
	std::vector<Wall> walls;
	//creates wall objects around perimeter of map
	Map(const sf::Vector2f& mapSize) {
		loadMap(mapSize);
	}

	void loadMap(const sf::Vector2f& mapSize) {
		//consider declare mapsize const in main
		float wallThickness = 0.01f;
		walls.push_back(Wall(sf::Vector2f(mapSize.x, wallThickness), sf::Vector2f(0.0, 0.0), sf::Color::Transparent)); //topwall 
		walls.push_back(Wall(sf::Vector2f(mapSize.x, wallThickness), sf::Vector2f(0, mapSize.y - wallThickness), sf::Color::Transparent)); //botwall
		walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(0.0, 0.0), sf::Color::Transparent)); //leftwall
		walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(mapSize.x - wallThickness, 0), sf::Color::Transparent)); //rightwall

		//walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(mapSize.x - 500, 0), sf::Color::Transparent));


		//obstacles
		//five pip design (100 x 100) obstacles
		walls.push_back(Wall(sf::Vector2f(100, 100), sf::Vector2f(450, 450), sf::Color::Magenta));
		walls.push_back(Wall(sf::Vector2f(100, 100), sf::Vector2f(225, 225), sf::Color::Magenta));
		walls.push_back(Wall(sf::Vector2f(100, 100), sf::Vector2f(675, 225), sf::Color::Magenta));
		walls.push_back(Wall(sf::Vector2f(100, 100), sf::Vector2f(225, 675), sf::Color::Magenta));
		walls.push_back(Wall(sf::Vector2f(100, 100), sf::Vector2f(675, 675), sf::Color::Magenta));

		walls.push_back(Wall(sf::Vector2f(80, 30), sf::Vector2f(0, 485), sf::Color::Magenta));
		walls.push_back(Wall(sf::Vector2f(80, 30), sf::Vector2f(mapSize.x - 80, 485), sf::Color::Magenta));
	}

	void draw(sf::RenderWindow& window) {
		for (auto& wall : walls) {
			window.draw(wall);
		}
	}

	virtual void update(const sf::Time& dt) override {
		//wall wont update. 90% sure I still needed to define this func tho to prevent compile issues.
	}

protected:

};

