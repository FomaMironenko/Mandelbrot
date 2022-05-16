#ifndef CANVAS
#define CANVAS
#endif

#include <iostream>
#include <memory>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>

#include "Backend/complex.h"


const unsigned char EN_KEY_UP_LOWCASE = 119;
const unsigned char EN_KEY_UP_UPPCASE = 87;
const unsigned char RU_KEY_UP_LOWCASE = 119;
const unsigned char RU_KEY_UP_UPPCASE = 87;

const unsigned char EN_KEY_RIGHT_LOWCASE = 100;
const unsigned char EN_KEY_RIGHT_UPPCASE = 68;
const unsigned char RU_KEY_RIGHT_LOWCASE = 100;
const unsigned char RU_KEY_RIGHT_UPPCASE = 68;

const unsigned char EN_KEY_DOWN_LOWCASE = 115;
const unsigned char EN_KEY_DOWN_UPPCASE = 83;
const unsigned char RU_KEY_DOWN_LOWCASE = 115;
const unsigned char RU_KEY_DOWN_UPPCASE = 83;

const unsigned char EN_KEY_LEFT_LOWCASE = 97;
const unsigned char EN_KEY_LEFT_UPPCASE = 65;
const unsigned char RU_KEY_LEFT_LOWCASE = 97;
const unsigned char RU_KEY_LEFT_UPPCASE = 65;


constexpr int size_x = 720;
constexpr int size_y = 480;


std::pair<int, int> getWindowSize();

void initCanvas();

void display(int d_x = 0, int d_y = 0);

void basic();

void key_pressed(unsigned char key, int x, int y);

void reshape(int width, int height);
