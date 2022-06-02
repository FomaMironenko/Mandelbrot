
#define GL_SILENCE_DEPRECATION
#include "emit_opengl.h"

#include "Backend/complex.h"
#include "Backend/image-processing.h"
#include "Backend/screenshot.h"

#include "GUI/shapes.h"
#include "GUI/canvas.h"
#include "GUI/colormap.h"


bool DO_DRAW_TARGET = false;

pixel_type data[size_x * size_y];
pixel_type picture[size_x * size_y * 3];
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
    apply_colormap(picture, data, size_x, size_y);
    glDrawPixels(size_x, size_y, GL_RGB, GL_UNSIGNED_BYTE, picture);
    if (DO_DRAW_TARGET) glDrawSector({.0, .0}, {.15, .15}, {1.0, 1.0, 1.0, .1});
    glFlush();
}

void pending_screen() {
    glColor4d(1., 1., 1., .4);
    glBegin(GL_QUADS);
        glVertex2d(-1, -1);
        glVertex2d(1, -1);
        glVertex2d(1, 1);
        glVertex2d(-1, 1);
    glEnd();
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
        case EN_KEY_EXIT:
            std::cout << "Session terminated by the user" << std::endl;
            exit(0); // needn't break
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
        case EN_KEY_COLORMAP_UPPCASE:
        case EN_KEY_COLORMAP_LOWCASE:
            CURR_COLORMAP = (CURR_COLORMAP + 1) % numel(colormaps);
            break;
        case EN_KEY_SCREENSHOT_UPPCASE:
        case EN_KEY_SCREENSHOT_LOWCASE:
            capture_screenshot(grid);
    }
    display();
}

std::pair<int, int> getWindowSize() {
    return {size_x/2, size_y/2};
}

void reshape(int width, int height) {
    // disable reshaping
    auto size_xy = getWindowSize();
    glutReshapeWindow(size_xy.first, size_xy.second);
}
