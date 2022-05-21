
#include "GUI/colormap.h"
#include <functional>


void ColorMap0 ( RGB_SRC_ARGS ) {
    R = src;
    G = src;
    B = src;
}

void ColorMap1 ( RGB_SRC_ARGS ) {
    complex::iter_type rMod = src % 100;
    R = (rMod <= 50) ? rMod :
        100 - rMod;
    R *= 4;
    G = 0;
    complex::iter_type bMod = src % 128;
    B = (bMod <= 64) ? bMod :
        128 - bMod;
    B *= 2;
}

void ColorMap2 ( RGB_SRC_ARGS ) {
    R = R = (src <= 50) ? 0 : 
        (src <= 100) ? 3*(src - 50) :
        (src <= 150) ? 3*(150 - src) :
        0;
    G = 0;
    B = (src <= 100) ? 0 : 
        (src <= 150) ? 4*(src - 100) :
        (src <= 200) ? 4*(200 - src) :
        0;
}

void ColorMap3 ( RGB_SRC_ARGS ) {
    R = (src <= 100) ? 0 : 
        (src <= 150) ? 2*(src - 100) :
        (src <= 200) ? 2*(200 - src) :
        0;
    G = 0;
    B = src;
}

void ColorMap4 ( RGB_SRC_ARGS ) {
    R = (src <= 180) ? 0 : 
        (src - 180) * 3;
    G = (src <= 40) ? 0 :
        (src <= 75) ? 4*(src - 40) : 
        (src <= 110) ? 4*(110 - src) :
        0;
    B = ( (src <= 50) ? 4*(50 - src) :
        0 ) + ( 
        (src <= 100) ? 0 :
        (src <= 150) ? 2*(src - 100) : 
        (src <= 200) ? 2*(200 - src) :
        0 ) + ( 
        (src <= 220) ? 0 :
        (src - 220) * 10 );
}


unsigned COLORMAP_TYPE = 0;


void fill( RGB_SRC_ARGS ) {
    switch (COLORMAP_TYPE) {
        case 0:
            ColorMap0(R, G, B, src);
            break;
        case 1:
            ColorMap1(R, G, B, src);
            break;
        case 2:
            ColorMap2(R, G, B, src);
            break;
        case 3:
            ColorMap3(R, G, B, src);
            break;
        case 4:
            ColorMap4(R, G, B, src);
            break;
    }
}

void apply_colormap(
    complex::iter_type * result,
    const complex::iter_type * source,
    int size_x, int size_y
) {
    for (unsigned i = 0; i < size_x * size_y; i++) {
        fill(
            result[3*i + 0],
            result[3*i + 1],
            result[3*i + 2],
            source[i]
        );
    }
}
