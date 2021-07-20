#pragma once

#include "snake.hpp"
#include <mutex>
#include <queue>

class Game
{
private:
    int score;
    typedef enum State {BOOT, START, PLAY, END, QUIT} State;
    State curState;
    Snake* snake;
    int height, width;
    int key;
    std::queue<int> keyPresses;
    std::mutex mtx;
    Apple* apple;
public:
    Game();
    ~Game();
    void run();
    void operator()();
    void setSnakeDirection();
};

