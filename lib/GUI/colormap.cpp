
#include "GUI/colormap.h"
#include <functional>


void ColorMap1 ( RGB_SRC_ARGS ) {
    R = src;
    G = src;
    B = 255;
}

void ColorMap2 ( RGB_SRC_ARGS ) {
    R = R = (src <= 50) ? 0 : 
        (src <= 100) ? 2*(src - 50) :
        (src <= 150) ? 2*(150 - src) :
        0;
    G = 0;
    B = (src <= 100) ? 0 : 
        (src <= 150) ? 2*(src - 100) :
        (src <= 200) ? 2*(200 - src) :
        0;;
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
            ColorMap1(R, G, B, src);
            break;
        case 1:
            ColorMap2(R, G, B, src);
            break;
        case 2:
            ColorMap3(R, G, B, src);
            break;
        case 3:
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