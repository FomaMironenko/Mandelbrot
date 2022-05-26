#ifndef SHAPES
#define SHAPES
#endif

#include <OpenGL/gl.h>
#include <array>

void glDrawCircle(
    const std::array<double, 2> center,
    const std::array<double, 2> radius,
    const std::array<double, 4> color
);

void glDrawText(

);