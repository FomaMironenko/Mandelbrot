#include <iostream>

#define GL_SILENCE_DEPRECATION
#include "emit_opengl.h"

#include "Backend/complex.h"
#include "GUI/canvas.h"


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_ALPHA);

    auto size_xy = getWindowSize();
    glutInitWindowSize(size_xy.first, size_xy.second);
    glutCreateWindow("Hello, fractal world!");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutKeyboardFunc(key_pressed);
    glutReshapeFunc(reshape);

    initCanvas();
    glutMainLoop();

    return EXIT_SUCCESS;
}