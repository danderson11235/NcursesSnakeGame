#pragma once

#include <vector>
#include <utility>
#include <ncurses.h>

#include "apple.hpp"

typedef enum Direction {UP, LEFT, DOWN, RIGHT} Direction;
class Snake
{
private:
    std::vector<std::pair<int, int>> tail;
    std::pair<int, int> head;
    Direction newDirection, curDirection;
    std::pair<int, int> getDirVec(Direction dir);
public:
    Snake(int startx, int starty);
    ~Snake();
    void drawSnake();
    void setDirection(Direction dir);
    Direction getDirection();
    bool moveSnake(int xMax, int yMax, Apple* apple);
};

