
#define GL_SILENCE_DEPRECATION
#include "emit_opengl.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include "GUI/shapes.h"


void glDrawCircle(
    const std::array<double, 2> center,
    const std::array<double, 2> radius,
    const std::array<double, 4> color
) {
    constexpr unsigned N = 32;
    constexpr double step_rad = 2.0 * M_PI / N;
    glColor4d(color[0], color[1], color[2], color[3]);
    glBegin(GL_TRIANGLES);
        for (unsigned k = 0; k < N; k++) {
            double x1 = center[0] + radius[0] * std::cos(step_rad * (k-1));
            double y1 = center[1] + radius[1] * std::sin(step_rad * (k-1));
            double x2 = center[0] + radius[0] * std::cos(step_rad * k);
            double y2 = center[1] + radius[1] * std::sin(step_rad * k);
            glVertex2d(.0, .0);
            glVertex2d(x1, y1);
            glVertex2d(x2, y2);
        }
    glEnd();
}