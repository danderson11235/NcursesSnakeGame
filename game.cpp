#include "game.hpp"
#include <ncurses.h>
#include <thread>
#include <chrono>

Game::Game()
{
    snake = new Snake(4, 4);
    score = 0;
    curState = BOOT;
    std::thread charThread(Game());
}

Game::~Game()
{
}

void Game::run()
{
    switch (curState)
    {
    case BOOT://Boot---------------------------------------------------------
        getmaxyx(stdscr, height, width);
        if (height < 6 && width < 10)
        {
            addstr("small");
            break;
        }
        box(stdscr, 0, 0);
        mvaddstr(1, 1, "Press d to start");
        snake->drawSnake();
        curState = START;
        break;
    case START://start-------------------------------------------------------
        int newHeight, newWidth;
        getmaxyx(stdscr, newHeight, newWidth);
        if (newWidth != width || newHeight != height) 
        {
            curState = BOOT;
            break;
        }
        mtx.lock();
        if (!keyPresses.empty() && keyPresses.front() == 'd')
        {
            keyPresses.pop();
            curState = PLAY;
        } else if (!keyPresses.empty())
        {
            keyPresses.pop();
        }
        mtx.unlock();
        break;
    case PLAY://play---------------------------------------------------------
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
        setSnakeDirection();
        if (!snake->moveSnake())
        {
            curState = END;
            break;
        }
        erase();
        snake->drawSnake();
        break;
    case END:

        break;
    default:
        break;
    }
    refresh();
}

void Game::operator()()
{
    while (curState != QUIT)
    {
        key = getch();
        mtx.lock();
        keyPresses.push(key);
        mtx.unlock();
    }
    
}

void Game::setSnakeDirection()
{
    mtx.lock();
    int curKey;
    if (!keyPresses.empty())
    {
        curKey = keyPresses.front();
        keyPresses.pop();
        switch (curKey)
        {
        case 'a':
            snake->setDirection(LEFT);
            break;
        case 's':
            snake->setDirection(DOWN);
            break;
        case 'd':
            snake->setDirection(RIGHT);
            break;
        case 'w':
            snake->setDirection(UP);
            break;
        default:
            break;
        }
    }
    while (!keyPresses.empty() && keyPresses.front() == curKey)
    {
        keyPresses.pop();
    }
}
