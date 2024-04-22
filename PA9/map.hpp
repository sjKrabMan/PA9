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
		walls.push_back(Wall(sf::Vector2f(mapSize.x, wallThickness), sf::Vector2f(0.0, 0.0), sf::Color::Transparent)); //topwall 
		walls.push_back(Wall(sf::Vector2f(mapSize.x, wallThickness), sf::Vector2f(0, mapSize.y - wallThickness), sf::Color::Transparent)); //botwall
		walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(0.0, 0.0), sf::Color::Transparent)); //leftwall
		walls.push_back(Wall(sf::Vector2f(wallThickness, mapSize.y), sf::Vector2f(mapSize.x - wallThickness, 0), sf::Color::Transparent)); //rightwall

		//obstacles
		walls.push_back(Wall(sf::Vector2f(20, 20), sf::Vector2f(10, 10), sf::Color::Green));
		walls.push_back(Wall(sf::Vector2f(20, 20), sf::Vector2f(250, 100), sf::Color::Green));
		walls.push_back(Wall(sf::Vector2f(20, 20), sf::Vector2f(300, 150), sf::Color::Green));
		walls.push_back(Wall(sf::Vector2f(20, 20), sf::Vector2f(900, 500), sf::Color::Green));

	}

	void draw(sf::RenderWindow& window) {
		for (auto& wall : walls) {
			window.draw(wall);
		}
	}

	virtual void update(const sf::Time& dt) override {
		//wall wont update. 90% sure I still needed to define this func tho to prevent compile issues.
	}

private:
	std::vector<Wall> walls;

};

