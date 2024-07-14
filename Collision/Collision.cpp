#include <SFML/Graphics.hpp>
#include "Sand.h"
#include <iostream>


sf::Vector2f fieldsize(350, 700);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    

    
    GridManger grid (fieldsize);

    grid.summon(19, 59);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        grid.update(window);

        //std::cout << grid.grid_to_screen(0, 0).x << " " << grid.grid_to_screen(0, 0).y << std::endl;

        /*window.clear();

        

        window.display();*/
    }


    return 0;
}