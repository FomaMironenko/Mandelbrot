// COMPLEX -- all complex logic implementation
#ifndef COMPLEX
#define COMPLEX

#include <OpenGL/gl.h>


using coord_type = double;
using pixel_type = GLubyte;


coord_type sq_abs(
    coord_type re, coord_type im
) noexcept;


inline void mandelbrot (
    coord_type &res_re, coord_type &res_im,
    coord_type prv_re,  coord_type prv_im,
    coord_type ini_re,  coord_type ini_im
) noexcept;


pixel_type belonging_rate(
    coord_type ini_re, coord_type ini_im
) noexcept;

#endif
