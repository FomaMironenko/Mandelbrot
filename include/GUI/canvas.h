#ifndef CANVAS
#define CANVAS

#include <iostream>
#include <memory>

#include "emit_opengl.h"

#include "Backend/complex.h"


const unsigned char EN_KEY_EXIT = 35; // '#'

const unsigned char EN_KEY_UP_LOWCASE = 119; // 'w'
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

const unsigned char EN_KEY_PLUS = 43;
const unsigned char EN_KEY_MINUS = 95;

const unsigned char EN_KEY_SPACE = 32;

const unsigned char EN_KEY_COLORMAP_UPPCASE = 67;
const unsigned char EN_KEY_COLORMAP_LOWCASE = 99;

const unsigned char EN_KEY_SCREENSHOT_UPPCASE = 84;
const unsigned char EN_KEY_SCREENSHOT_LOWCASE = 116;


constexpr int size_x = 720;
constexpr int size_y = 480;


std::pair<int, int> getWindowSize();

void initCanvas();

void display();

void pending_screen();

void key_pressed(unsigned char key, int x, int y);

void reshape(int width, int height);

#endif
