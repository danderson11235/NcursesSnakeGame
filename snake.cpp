#include "snake.hpp"

Snake::Snake(int startx, int starty)
{
    head = {startx, starty};
    for (int i = 0; i < 2; i++)
    {
        tail.push_back({startx - 2 + i, starty});
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

bool Snake::moveSnake(int xMax, int yMax, Apple * apple)
{   
    // if the new direction is opposite of old dir set new to old and continue
    if ((curDirection != newDirection) && (curDirection + newDirection % 2) == 1) 
        {newDirection = curDirection;}
    // if the direction that the snake wants to move is wall/tail end
    std::pair<int, int> dirVec = getDirVec(newDirection);
    if (head.first + dirVec.first >= xMax || head.first + dirVec.first <= 0 || 
        head.second + dirVec.second >= xMax || head.second + dirVec.second <= 0) return false;
    if (mvinch(head.second+dirVec.second, head.first+dirVec.first) == '#') return false;
    // if the position contains an apple then then inc tail at head and move head
    // retrun true
    if (head.first+dirVec.first == apple->getPosition().first && 
        head.second+dirVec.second == apple->getPosition().second)
    {
        apple->eat();
        tail.push_back(head);
    }
    else // move the tail from the back to the front
    {
        for (int i = 0; i < tail.size() - 1; i++)
        {
            tail[i] = tail[i + 1];
        }
        tail[tail.size() -1] = head;
    }
    head = {head.first+dirVec.first, head.second+dirVec.second};
    return true;
}

std::pair<int, int> Snake::getDirVec(Direction dir)
{
    switch (dir)
    {
    case UP:
        return {0, -1};
    case DOWN:
        return {0, 1};
    case LEFT:
        return {-1, 0};
    case RIGHT:
        return {1, 0};
    default:
        break;
    }
    return {0, 0};
}

void Snake::setDirection(Direction dir)
{
    newDirection = dir;
}
