
#include "GUI/colormap.h"

#include <iostream>


unsigned CURR_COLORMAP = 0;

void apply_colormap(
    complex::iter_type * result,
    const complex::iter_type * source,
    int size_x, int size_y
) {
    auto cmap = colormaps[CURR_COLORMAP].cmap;
    for (unsigned i = 0; i < size_x * size_y; i++) {
        cmap(
            result[3*i + 0],
            result[3*i + 1],
            result[3*i + 2],
            source[i]
        );
    }
}
