#include "game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

Game::Game() {
    initgraph(COL * BLOCK_SIZE, ROW * BLOCK_SIZE);
    snake = new Snake();
    generate_food();
}

void Game::generate_food() {
    food_x = rand() % COL;
    food_y = rand() % ROW;
}

void Game::draw_food() {
    setfillcolor(YELLOW);
    solidrectangle((food_x + 1) * BLOCK_SIZE, (food_y + 1) * BLOCK_SIZE,
        (food_x + 2) * BLOCK_SIZE, (food_y + 2) * BLOCK_SIZE);
}

bool Game::check_food(Snake* p) {
    if (p->getX() == food_x && p->getY() == food_y) {
        snake->grow();
        return true;
    }
    return false;
}

bool Game::check_crash(Snake* p) {
    return p->getX() < 0 || p->getX() >= COL || p->getY() < 0 || p->getY() >= ROW;
}

void Game::run() {
    while (1) {
        snake->draw();
        draw_food();
        if (check_food(snake)) {
            generate_food();
        }
        int dx = 0, dy = 0;
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'w') {
                dx = 0, dy = -1;
            }
            else if (ch == 's') {
                dx = 0, dy = 1;
            }
            else if (ch == 'a') {
                dx = -1, dy = 0;
            }
            else if (ch == 'd') {
                dx = 1, dy = 0;
            }
        }
        snake->move(dx, dy);
        if (check_crash(snake)) {
            break;
        }
        Sleep(100);
        cleardevice();
    }
    _getch();
    closegraph();
}
