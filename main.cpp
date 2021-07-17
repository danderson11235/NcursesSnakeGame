#include <ncurses.h>
#include "game.hpp"

void main ()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    Game game;
    while (true)
    {
        game.run();
    }
    

    endwin();    
}