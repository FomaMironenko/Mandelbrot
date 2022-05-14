#include "Backend/complex.h"


using d_type = complex::data_type;
using i_type = complex::iter_type;

const i_type MAX_ITERS = 255;


inline void complex::mandelbrot (
    d_type &res_re, d_type &res_im,
    d_type prv_re,  d_type prv_im,
    d_type ini_re,  d_type ini_im
) noexcept {
    res_re = prv_re * prv_re - prv_im * prv_im + ini_re;
    res_im = prv_re * prv_im + ini_im;
}


d_type complex::sq_abs(
    d_type re, d_type im
) noexcept {
    return re * re + im * im;
}

i_type complex::belonging_rate(
    d_type ini_re, d_type ini_im
) noexcept {
    d_type cur_re = ini_re, cur_im = ini_im;
    d_type sq_re, sq_im; 
    i_type i = 0;
    for ( ; i < MAX_ITERS; i++) {
        sq_re = cur_re * cur_re;
        sq_im = cur_im * cur_im;
        if (sq_re + sq_im > 4) break;
        cur_im = cur_re * cur_im + ini_im;
        cur_re = sq_re  - sq_im  + ini_re;
    }
    return i;
}
