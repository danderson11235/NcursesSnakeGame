#include "apple.hpp"

Apple::Apple(int x, int y)
{
    position = {x, y};
    eaten = false;
}

std::pair<int, int> Apple::getPosition()
{
    return position;
}

bool Apple::isEaten()
{
    return eaten;
}

void Apple::eat()
{
    eaten = true;
}