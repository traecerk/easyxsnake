#ifndef _GAME_H_
#define _GAME_H_

#include "snake.h"



class Game {
public:
    Game();
    void run();

private:
    Snake* snake;
    int food_x, food_y;
    void generate_food();
    void draw_food();
    bool check_food(Snake* p);
    bool check_crash(Snake* p);
};

#endif
