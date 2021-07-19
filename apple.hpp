#pragma once

#include <utility>

class Apple
{
private:
    std::pair<int, int> position;
    bool eaten;
public:
    Apple(int x, int y);
    ~Apple();
    std::pair<int, int> getPosition();
    bool isEaten();
    void eat();
};
