#include "GridManger.h"
#include <SFML/Window/Mouse.hpp>
#include <queue>



sf::Vector2f GridManger::grid_to_screen(float x, float y) {
    sf::Vector2f pos(x, y);
    return grid_to_screen(pos);

}

sf::Vector2f GridManger::grid_to_screen(sf::Vector2f pos) {
    pos.y = size * 2 - 1 - pos.y;
    return pos * (fieldsize.x / size) + sf::Vector2f(400 - fieldsize.x / 2, 0);
}

bool GridManger::isEmpty(int x, int y) {
    if (x < 0 || x >= size || y < 0 || y >= size * 2)
        return false;
    return grid[y][x] == nullptr;
}

bool GridManger::isEmpty(sf::Vector2f pos)
{
    return isEmpty((int)pos.x, (int)pos.y);
}

bool GridManger::move(sf::Vector2f pos, sf::Vector2f topos)
{
    if (isEmpty(topos) && !moved[(int)pos.y][(int)pos.x]) {
        grid[(int)pos.y][(int)pos.x]->gridpos = topos;
        grid[(int)topos.y][(int)topos.x] = grid[(int)pos.y][(int)pos.x];
        grid[(int)pos.y][(int)pos.x] = nullptr;
        moved[(int)topos.y][(int)topos.x] = true;
        bool flag = false;
        /*for (int i = 0; i < size; i++) {
            if (grid[(int)topos.y][i] == nullptr) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            for (int i = 0; i < size; i++) {
                delete grid[(int)topos.y][i];
                grid[(int)topos.y][i] = nullptr;
            }
        }*/

        return true;
    }
    return false;
}

void GridManger::update(sf::RenderWindow& window)
{

    if (tickclock.getElapsedTime().asSeconds() >= 0) {
        tickclock.restart();
        window.clear();

        for (int i = -30; i < 30; i++) {

            summon((sf::Mouse::getPosition(window).x - (400 - fieldsize.x / 2)) / (fieldsize.x) * size + i, size * 2 - 1);
        }
        //s/*pawn += dir;
        //if (spawn == 29 || spawn == 0) {
        //    dir *= 0;
        //}*/

        field.setPosition((400 - fieldsize.x / 2) - 450, 0);

        window.draw(field);

        field.setPosition(200, 700);

        window.draw(field);

        field.setPosition((400 + fieldsize.x / 2), 0);


        window.draw(field);

        for(int i = 0;i < size;i++)
            for (int x = 0; x < size * 2; x++) {
                if (grid[x][i]) {
                    grid[x][i]->update(&window);
                }
            }

        int toremove = -1;
        for (int i = 0; i < size * 2; i++) {
            bool flag = false;
            for (int x = 0; x < size; x++) {
                if (grid[i][x] == nullptr) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
            toremove = i;
        }

        for (int i = 0; i < std::min(10,toremove); i++) {
            for (int x = 0; x < size; x++){ 
                delete grid[i][x];
                grid[i][x] = nullptr;
            }
        }
        window.display();
        for (int i = 0; i < size; i++)
            for (int x = 0; x < size * 2; x++) {
                moved[x][i] = false;
            }
    }
}

void GridManger::summon(int x, int y)
{
    if (isEmpty(x, y)){
        grid[y][x] = new Sand(this, sf::Vector2f(x, y));
    }
}

GridManger::GridManger(sf::Vector2f fieldsize) {
    tickclock.restart();

    this->fieldsize = fieldsize;

    field.setSize(sf::Vector2f(450.0f, 1000.0f));

    field.setFillColor(sf::Color(200, 200, 200));
    for(int i = 0;i < size;i++)
        for (int x = 0; x < size * 2; x++) {
            grid[x][i] = nullptr;
        }
}