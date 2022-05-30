#ifndef SHAPES
#define SHAPES

#define _USE_MATH_DEFINES
#include <cmath>

#include <OpenGL/gl.h>
#include <array>

void glDrawSector(
    const std::array<double, 2> &center,
    const std::array<double, 2> &radius,
    const std::array<double, 4> &color,
    double begin_rad = 0,
    double end_rad = 2.0 * M_PI
);

void glDrawText(

);

#endif
