#pragma once
#include "Sand.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>


class Sand;


const int size = 100;
class GridManger
{

	Sand *grid[size * 2][size];
	sf::Clock tickclock;
	sf::RectangleShape field;
	int spawn = 0;
	int dir = 1;
	bool moved[size * 2][size*2];

public:
	sf::Vector2f fieldsize;
	GridManger() = default;
	GridManger(sf::Vector2f fieldsize);
	sf::Vector2f grid_to_screen(sf::Vector2f pos);
	sf::Vector2f grid_to_screen(float x, float y);
	bool isEmpty(sf::Vector2f pos);
	bool isEmpty(int x, int y);
	bool move(sf::Vector2f pos, sf::Vector2f topos);
	void update(sf::RenderWindow& window);
	void summon(int x, int y);
};

