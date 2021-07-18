#include <vector>
#include <utility>
#include <ncurses.h>

typedef enum Direction {UP, DOWN, LEFT, RIGHT};
class Snake
{
private:
    std::vector<std::pair<int, int>> tail;
    std::pair<int, int> head;
    Direction newDirection, curDirection;
public:
    Snake(int startx, int starty);
    ~Snake();
    void drawSnake();
    void setDirection(Direction dir);
    Direction getDirection();
    bool moveSnake();
};

