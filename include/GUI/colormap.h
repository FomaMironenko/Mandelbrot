#ifndef COLORMAP
#define COLORMAP
#endif

#include <iostream>

#include "Backend/complex.h"


#define RGB_SRC_ARGS pixel_type & R, pixel_type & G, pixel_type & B, pixel_type src

using f_type = void (*)(RGB_SRC_ARGS);




void apply_colormap(
    pixel_type * result,
    const pixel_type * source,
    int size_x, int size_y
);


// get compile-time length of a compile-time array
template<size_t n, class T>
constexpr size_t numel(const T(&) [n]) {
    return n;
}

struct ColorMap {
    const char *name;
    const f_type cmap; // function reference

    // BE CAREFUL TO PASS ONLY STRING LITERALS
    constexpr ColorMap(
        const char *name,
        const f_type cmap
    ): name(std::move(name)), cmap(cmap) { }
};




extern unsigned CURR_COLORMAP;

/* An easy-maintainable list of all colormaps.
 * If you want to create a new colormap, simply add it here.
 * It will be processed automatically and you don't need to
 * take care of anything else.
 */
constexpr ColorMap colormaps[] = {

    ColorMap("Grayscale",
    [](RGB_SRC_ARGS) {
        R = src;
        G = src;
        B = src;
    }),

    ColorMap("Magic Contrast",
    [](RGB_SRC_ARGS) {
        pixel_type rMod = src % 100;
        R = (rMod <= 50) ? rMod :
            100 - rMod;
        R *= 4;
        G = 0;
        pixel_type bMod = src % 128;
        B = (bMod <= 64) ? bMod :
            128 - bMod;
        B *= 2;
    }),

    ColorMap("Mysterious dark",
    [](RGB_SRC_ARGS){
        R = R = (src <= 50) ? 0 : 
            (src <= 100) ? 3*(src - 50) :
            (src <= 150) ? 3*(150 - src) :
            0;
        G = 0;
        B = (src <= 100) ? 0 : 
            (src <= 150) ? 4*(src - 100) :
            (src <= 200) ? 4*(200 - src) :
        0;
    }),

    ColorMap("Lightning",
    [](RGB_SRC_ARGS) {
        R = (src <= 100) ? 0 : 
            (src <= 150) ? 2*(src - 100) :
            (src <= 200) ? 2*(200 - src) :
            0;
        G = 0;
        B = src;
    }),

    ColorMap("Acid",
    [](RGB_SRC_ARGS) {
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
    })
};
