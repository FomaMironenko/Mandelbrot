#include <iostream>

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include "Backend/complex.h"
#include "GUI/canvas.h"


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(size_x, size_y);
    glutCreateWindow("Hello!");

    glutDisplayFunc(basic);
    glutKeyboardFunc(key_pressed);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return EXIT_SUCCESS;
}