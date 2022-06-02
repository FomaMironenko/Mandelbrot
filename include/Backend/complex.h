// COMPLEX -- all complex logic implementation
#ifndef COMPLEX
#define COMPLEX

#include "emit_opengl.h"


namespace complex {

using data_type = double;
using iter_type = GLubyte;


data_type sq_abs(
    data_type re, data_type im
) noexcept;


inline void mandelbrot (
    data_type &res_re, data_type &res_im,
    data_type prv_re,  data_type prv_im,
    data_type ini_re,  data_type ini_im
) noexcept;


iter_type belonging_rate(
    data_type ini_re, data_type ini_im
) noexcept;

}

#endif
