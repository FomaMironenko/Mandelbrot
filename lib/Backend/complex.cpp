#include "Backend/complex.h"


const pixel_type MAX_ITERS = 255;


inline void mandelbrot (
    coord_type &res_re, coord_type &res_im,
    coord_type prv_re,  coord_type prv_im,
    coord_type ini_re,  coord_type ini_im
) noexcept {
    res_re = prv_re * prv_re - prv_im * prv_im + ini_re;
    res_im = prv_re * prv_im + ini_im;
}


coord_type sq_abs(
    coord_type re, coord_type im
) noexcept {
    return re * re + im * im;
}

pixel_type belonging_rate(
    coord_type ini_re, coord_type ini_im
) noexcept {
    coord_type cur_re = ini_re, cur_im = ini_im;
    coord_type sq_re, sq_im; 
    pixel_type i = 0;
    for ( ; i < MAX_ITERS; i++) {
        sq_re = cur_re * cur_re;
        sq_im = cur_im * cur_im;
        if (sq_re + sq_im > 4) break;
        cur_im = 2 * cur_re * cur_im + ini_im;
        cur_re = sq_re  - sq_im  + ini_re;
    }
    return i;
}
