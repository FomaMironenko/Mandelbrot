#include "Backend/complex.h"


using d_type = Complex::data_type;


inline void _mandelbrot (
    d_type &res_re, d_type &res_im,
    d_type src_re,  d_type src_im
) {
    res_re = src_re * src_re - src_im * src_im + Complex::c_re;
    res_im = src_re * src_im + Complex::c_im;
}


void Complex::process(
    d_type &res_re, d_type &res_im,
    d_type src_re,  d_type src_im
) {
    _mandelbrot(res_re, res_im, src_re, src_im);
}
