#include "Backend/complex.h"


using d_type = Complex::data_type;
using i_type = Complex::iter_type;

const i_type MAX_ITERS = 255;


inline void _mandelbrot (
    d_type &res_re, d_type &res_im,
    d_type prv_re,  d_type prv_im,
    d_type ini_re,  d_type ini_im
) noexcept {
    res_re = prv_re * prv_re - prv_im * prv_im + ini_re;
    res_im = prv_re * prv_im + ini_im;
}


void Complex::process(
    d_type &res_re, d_type &res_im,
    d_type prv_re,  d_type prv_im,
    d_type ini_re,  d_type ini_im
) noexcept {
    _mandelbrot(res_re, res_im, prv_re, prv_im, ini_re, ini_im);
}


d_type sq_abs(
    d_type re, d_type im
) noexcept {
    return re * re + im * im;
}

i_type belonging_rate(
    d_type ini_re, d_type ini_im
) noexcept {
    d_type cur_re = ini_re, cur_im = ini_im;
    i_type i = 0;
    for ( ; i < MAX_ITERS-1; i++) {
        if (sq_abs(cur_re, cur_im) > 2) break;
        Complex::process(
            cur_re, cur_im, cur_re, cur_im, ini_re, ini_re);
    }
    return i;
}
