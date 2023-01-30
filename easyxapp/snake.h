#ifndef SNAKE_H
#define SNAKE_H

#include <graphics.h>

const int ROW = 20;
const int COL = 20;
const int BLOCK_SIZE = 20;

class Snake {
public:
    Snake();
    void draw();
    void grow();
    void move(int dx, int dy);
    int getX();
    int getY();
    
private:
    int x[100], y[100],len;
};

#endif
