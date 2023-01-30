#include "snake.h"
#include "easyx.h"

using namespace std;

Snake::Snake() {
    x[0] = 10;
    y[0] = 10;
    len = 1;
}

void Snake::move(int dx, int dy) {
    for (int i = len - 1; i > 0; i--) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    x[0] += dx;
    y[0] += dy;
    if (len >= 4) {
        for (int i = 1; i < len; i++) {
            if (x[0] == x[i] && y[0] == y[i]) {
                exit(0);  // End game
            }
        }
    }
    
	
}

int Snake::getX() {
    return x[0];
}

int Snake::getY() {
    return y[0];
}


void Snake::draw() {
    setfillcolor(RED);
    for (int i = 0; i < len; i++) {
        solidrectangle((x[i] + 1) * BLOCK_SIZE, (y[i] + 1) * BLOCK_SIZE,
            (x[i] + 2) * BLOCK_SIZE, (y[i] + 2) * BLOCK_SIZE);
    }
}

void Snake::grow() {
    len++;
    x[len - 1] = x[len - 2];
    y[len - 1] = y[len - 2];
}
