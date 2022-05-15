#ifndef CANVAS
#define CANVAS
#endif

#include <iostream>
#include <memory>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>

#include "Backend/complex.h"


using pixel_type = complex::iter_type;

const unsigned char MY_KEY_UP = 119;
const unsigned char MY_KEY_RIGHT = 100;
const unsigned char MY_KEY_DOWN = 115;
const unsigned char MY_KEY_LEFT = 97;

constexpr size_t size_x = 720;
constexpr size_t size_y = 480;


void display(int d_x = 0, int d_y = 0);

void basic();

void key_pressed(unsigned char key, int x, int y);

void reshape(GLsizei width, GLsizei height);
