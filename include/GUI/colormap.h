#ifndef COLORMAP
#define COLORMAP
#endif


#include <array>

#include "Backend/complex.h"


extern unsigned COLORMAP_TYPE;
constexpr unsigned N_COLORMAPS = 5;

#define RGB_SRC_ARGS complex::iter_type & R, complex::iter_type & G, complex::iter_type & B, complex::iter_type src

void fill( RGB_SRC_ARGS );

void apply_colormap(
    complex::iter_type * result,
    const complex::iter_type * source,
    int size_x, int size_y
);
