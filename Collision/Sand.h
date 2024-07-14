#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GridManger.h"


class GridManger;


extern const int size;

class Sand
{
public:
	GridManger* grid = nullptr;
	sf::RectangleShape* rect;
	sf::Vector2f gridpos;
	bool deleted = false;
	

	Sand();
	Sand(GridManger* grid, sf::Vector2f pos);
	void update(sf::RenderWindow* window);

};

