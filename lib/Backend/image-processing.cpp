#include <iostream>
#include <algorithm>

#include "Backend/image-processing.h"

void shift_matrix(
    pixel_type * data,
    int size_x, int size_y,
    Grid & grid,
    int d_x, int d_y
) {
    if (d_x != 0 && d_y != 0) {
        shift_matrix(data, size_x, size_y, grid, 0, d_y);
        shift_matrix(data, size_x, size_y, grid, d_x, 0);
        return;
    }
    if (d_x == 0 && d_y == 0) return;

    // update grid structure
    grid.x_offset += d_x * grid.spacing;
    grid.y_offset += d_y * grid.spacing;
    // range to be queried to mandelbrot
    int query_rngx[2] = {0, size_x};
    int query_rngy[2] = {0, size_y};

    // vertical shift
    if (d_y < 0) {
        for (int dst_row = size_y - 1; dst_row >= -d_y; dst_row--) {
            std::memcpy(
                data + dst_row * size_x,        // destination
                data + (dst_row + d_y) * size_x,// source
                size_x * sizeof(pixel_type)
            );
        }
        query_rngy[1] = -d_y;
    }
    if (d_y > 0) {
        for (int dst_row = 0; dst_row < size_y - d_y; dst_row++) {
            std::memcpy(
                data + dst_row * size_x,        // destination
                data + (dst_row + d_y) * size_x,// source
                size_x * sizeof(pixel_type)
            );
        }
        query_rngy[0] = size_y - d_y;
    }

    // horizontal shift
    int keep_size = size_x - std::abs(d_x);
    if (d_x < 0 && keep_size > 0) {
        for (int row = 0; row < size_y; row++) {
            std::memcpy(
                data + row * size_x - d_x,      //destination
                data + row * size_x,            // source
                keep_size * sizeof(pixel_type)
            );
        }
        query_rngx[1] = -d_x;
    }
    if (d_x > 0 && keep_size > 0) {
        for (int row = 0; row < size_y; row++) {
            std::memcpy(
                data + row * size_x,            //destination
                data + row * size_x + d_x,      // source
                keep_size * sizeof(pixel_type)
            );
        }
        query_rngx[0] = size_x - d_x;
    }

    // time expensive mandelbrot queries
    int mid_x = size_x / 2;
    int mid_y = size_y / 2;
    for (int row = query_rngy[0]; row < query_rngy[1]; row++) {
        for (int col = query_rngx[0]; col < query_rngx[1]; col++) {
            data[row*size_x + col] = 
            complex::belonging_rate(
                (col - mid_x) * grid.spacing + grid.x_offset,
                (row - mid_y) * grid.spacing + grid.y_offset
            );
        }
    }
}