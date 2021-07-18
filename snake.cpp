#include "snake.hpp"

Snake::Snake(int startx, int starty)
{
    head = {startx, starty};
    for (int i = 0; i < 2; i++)
    {
        tail.push_back({startx - i, starty});
    }
    curDirection = RIGHT;

}

Snake::~Snake()
{
}

void Snake::drawSnake()
{
    mvaddch(head.second, head.first, '#');
    for (std::pair<int, int> scale : tail)
    {
        mvaddch(scale.second, scale.first, '#');
    }
}

bool Snake::moveSnake(int, xMax, int yMax)
{
    if (newDirection == curDirection)
    {
        switch (curDirection)
        {
            case UP:

        }
    } 
    else 
    {

    }
}
