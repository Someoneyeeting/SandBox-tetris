#include "Sand.h"
#include <iostream>
#include <SFML/Window/Mouse.hpp>

Sand::Sand()
{
}

Sand::Sand(GridManger* grid, sf::Vector2f pos) {

	this->grid = grid;
	this->gridpos = pos;
	rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(grid->fieldsize.x / size, grid->fieldsize.x / size));
	rect->setFillColor(sf::Color(rand() % 200,rand() % 200,rand() % 200));
	rect->setPosition(grid->grid_to_screen(pos));


}




void Sand::update(sf::RenderWindow* window) {
	if (this->grid->move(gridpos, gridpos + sf::Vector2f(0, -1)));
	else if (this->grid->move(gridpos, gridpos + sf::Vector2f(1, -1)));
	else if (this->grid->move(gridpos, gridpos + sf::Vector2f(-1, -1)));

	if (deleted)
		return;

	rect->setPosition(grid->grid_to_screen(gridpos));
	//rect->setPosition(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
	//std::cout << rect->getPosition().x << " " << rect->getPosition().y << std::endl;

	window->draw(*rect);
}
