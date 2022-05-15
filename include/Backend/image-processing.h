#ifndef IMAGE_PROCESSING
#define IMAGE_PROCESSING
#endif


#include <iostream>

#include "Backend/complex.h"


using pixel_type = complex::iter_type;
using d_type = complex::data_type;


struct Grid {
    d_type scale;
    d_type x_offset;
    d_type y_offset;
};

void shift_matrix(
    pixel_type * data,
    size_t size_x, size_t size_y,
    Grid & grid,
    int d_x, int d_y
);

void scale_matrix(
    pixel_type * data,
    size_t size_x, size_t size_y,
    const Grid & grid,
    unsigned nom, unsigned denom
);
