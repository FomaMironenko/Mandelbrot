#ifndef COLORMAP
#define COLORMAP
#endif


#include <array>

#include "Backend/complex.h"



void apply_colormap(
    complex::iter_type * result,
    const complex::iter_type * source,
    int size_x, int size_y
);

#define RGB_SRC_ARGS complex::iter_type & R, complex::iter_type & G, complex::iter_type & B, complex::iter_type src

void fill( RGB_SRC_ARGS );

extern unsigned COLORMAP_TYPE;
constexpr unsigned N_COLORMAPS = 4;

void ColorMap1 ( RGB_SRC_ARGS );
void ColorMap2 ( RGB_SRC_ARGS );
void ColorMap3 ( RGB_SRC_ARGS );
void ColorMap4 ( RGB_SRC_ARGS );
void ColorMap5 ( RGB_SRC_ARGS );
void ColorMap6 ( RGB_SRC_ARGS );
