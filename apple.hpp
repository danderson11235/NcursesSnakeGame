#pragma once

#include <utility>

class Apple
{
private:
    std::pair<int, int> position;
public:
    Apple(int x, int y);
    ~Apple();
};
