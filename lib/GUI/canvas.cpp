
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include "Backend/complex.h"
#include "GUI/canvas.h"


using d_type = complex::data_type;

void display(int d_x, int d_y) {
    static int offset_x = 0;
    static int offset_y = 0;
    offset_x += d_x;
    offset_y += d_y;

    pixel_type data[size_x * size_y];
    int cln = 0, row = 0;
    d_type mid_x = size_x / 2.0, mid_y = size_y / 2.0;
    d_type x = 0, y = 0;
    for (int i = 0; i < size_x * size_y; i++) {
        cln = i % size_x;
        row = i / size_x;
        x = 2 * ((d_type)cln - mid_x) / size_x + 
            (d_type)offset_x / size_x;
        y = 2 * ((d_type)row - mid_y) / size_y +
            (d_type)offset_y / size_y;
        data[i] = complex::belonging_rate(x, y);
    }
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

void reshape(GLsizei width, GLsizei height) {
    // disable reshaping
}
