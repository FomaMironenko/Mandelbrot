
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include "Backend/complex.h"
#include "Backend/image-processing.h"
#include "GUI/canvas.h"


pixel_type data[size_x * size_y];
Grid grid;


void initCanvas() {
    grid.spacing = 4.0 / size_x;
    grid.x_offset = 0;
    grid.y_offset = 0;

    int mid_x = size_x / 2;
    int mid_y = size_y / 2;

    for (int row = 0; row < size_y; row++) {
        for (int col = 0; col < size_x; col++) {
            data[row*size_x + col] = 
            complex::belonging_rate(
                (col - mid_x) * grid.spacing + grid.x_offset,
                (row - mid_y) * grid.spacing + grid.y_offset
            );
        }
    }
}

void display(int d_x, int d_y) {
    shift_matrix(data, size_x, size_y, grid, d_x, d_y);
    glDrawPixels(size_x, size_y, GL_BLUE, GL_UNSIGNED_BYTE, data);
    glFlush();
}

void basic() {
    display();
}

void key_pressed(unsigned char key, int x, int y) {
    int step = 80;
    switch (key) {
        case MY_KEY_UP:
            display(0, step);
            break;
        case MY_KEY_DOWN:
            display(0, -step);
            break;
        case MY_KEY_LEFT:
            display(-step, 0);
            break;
        case MY_KEY_RIGHT:
            display(step, 0);
            break;
    }
}

std::pair<int, int> getWindowSize() {
    return {size_x, size_y};
}

void reshape(int width, int height) {
    // disable reshaping
    auto size_xy = getWindowSize();
    glutReshapeWindow(size_xy.first, size_xy.second);
}
