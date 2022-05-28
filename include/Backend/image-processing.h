#ifndef IMAGE_PROCESSING
#define IMAGE_PROCESSING


#include <iostream>

#include "Backend/complex.h"


struct Grid {
    coord_type spacing;
    coord_type x_offset;
    coord_type y_offset;
};

void resolve_queries(
    pixel_type * data,
    int size_x, int size_y,
    const Grid & grid,
    int query_rngx[2], int query_rngy[2]
);

void shift_matrix(
    pixel_type * data,
    int size_x, int size_y,
    Grid & grid,
    int d_x, int d_y
);

void scale_matrix(
    pixel_type * data,
    int size_x, int size_y,
    Grid & grid,
    unsigned nom, unsigned denom
);

#endif
