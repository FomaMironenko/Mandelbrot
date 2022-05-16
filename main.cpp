#include <iostream>

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include "Backend/complex.h"
#include "GUI/canvas.h"


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    auto size_xy = getWindowSize();
    glutInitWindowSize(size_xy.first, size_xy.second);
    glutCreateWindow("Hello!");

    glutDisplayFunc(basic);
    glutKeyboardFunc(key_pressed);
    glutReshapeFunc(reshape);

    initCanvas();
    glutMainLoop();

    return EXIT_SUCCESS;
}