
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include "Backend/complex.h"
#include "Backend/image-processing.h"

#include "GUI/shapes.h"
#include "GUI/canvas.h"


bool DO_DRAW_TARGET = false;

pixel_type data[size_x * size_y];
Grid grid;


void initCanvas() {
    grid.spacing = 4.0 / size_x;
    grid.x_offset = 0;
    grid.y_offset = 0;

    int query_rngx[2] = {0, size_x};
    int query_rngy[2] = {2, size_y};
    resolve_queries(
        data, size_x, size_y,
        grid, query_rngx, query_rngy
    );
}

void display() {
    glDrawPixels(size_x, size_y, GL_BLUE, GL_UNSIGNED_BYTE, data);
    if (DO_DRAW_TARGET) glDrawCircle({.0, .0}, {.15, .15}, {1.0, 1.0, 1.0, .1});
    glFlush();
}


void do_shift(int d_x, int d_y) {
    shift_matrix(data, size_x, size_y, grid, d_x, d_y);
}

void do_scale(unsigned nom, unsigned denom) {
    scale_matrix(data, size_x, size_y, grid, nom, denom);
}

void key_pressed(unsigned char key, int x, int y) {
    int step = 30;
    unsigned nom = 5;
    unsigned den = 4;
    
    switch (key) {
        case EN_KEY_UP_LOWCASE:
        case EN_KEY_UP_UPPCASE:
            do_shift(0, step);
            break;
        case EN_KEY_DOWN_LOWCASE:
        case EN_KEY_DOWN_UPPCASE:
            do_shift(0, -step);
            break;
        case EN_KEY_LEFT_LOWCASE:
        case EN_KEY_LEFT_UPPCASE:
            do_shift(-step, 0);
            break;
        case EN_KEY_RIGHT_LOWCASE:
        case EN_KEY_RIGHT_UPPCASE:
            do_shift(step, 0);
            break;
        case EN_KEY_PLUS:
            do_scale(nom, den);
            break;
        case EN_KEY_MINUS:
            do_scale(den, nom);
            break;
        case EN_KEY_SPACE:
            DO_DRAW_TARGET = !DO_DRAW_TARGET;
            break;
    }
    display();
}

std::pair<int, int> getWindowSize() {
    return {size_x, size_y};
}

void reshape(int width, int height) {
    // disable reshaping
    auto size_xy = getWindowSize();
    glutReshapeWindow(size_xy.first, size_xy.second);
}
