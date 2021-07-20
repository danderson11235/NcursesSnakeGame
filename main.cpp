#include <ncurses.h>
#include "game.hpp"

int main ()
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
    return 1;  
}