#include <iostream>
#include <algorithm>
#include <thread>

#include "Backend/image-processing.h"


constexpr unsigned nThreads = 8;
std::thread threads[nThreads];

void work(
    pixel_type * data,
    int size_x, int size_y,
    const Grid & grid,
    int query_rngx[2], int query_rngy[2],
    unsigned nThreads, unsigned curThread
) {
    int mid_x = size_x / 2;
    int mid_y = size_y / 2;
    int small_size_x = query_rngx[1] - query_rngx[0];
    int small_size_y = query_rngy[1] - query_rngy[0];
    int total_queries = small_size_x * small_size_y;
    int row = 0, col = 0;
    for (int i = curThread; i < total_queries; i += nThreads) {
        row = i / small_size_x + query_rngy[0];
        col = i % small_size_x + query_rngx[0];
        data[row*size_x + col] = 
        belonging_rate(
            (col - mid_x) * grid.spacing + grid.x_offset,
            (row - mid_y) * grid.spacing + grid.y_offset
        );
    }
}

void resolve_queries(
    pixel_type * data,
    int size_x, int size_y,
    const Grid & grid,
    int query_rngx[2], int query_rngy[2]
) {
    for (unsigned i = 0; i < nThreads; i++) {
        threads[i] = std::thread(work, 
            data, size_x, size_y, grid,
            query_rngx, query_rngy, nThreads, i
        );
    }
    for (unsigned i = 0; i < nThreads; i++) {
        threads[i].join();
    }
}


void vertical_shift(
    pixel_type * data,
    int size_x, int size_y,
    Grid & grid,
    int d_y
) {
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
    // time expensive mandelbrot queries
    resolve_queries(
        data, size_x, size_y, 
        grid, query_rngx, query_rngy
    );
}

void horizontal_shift(
    pixel_type * data,
    int size_x, int size_y,
    Grid & grid,
    int d_x
) {
    grid.x_offset += d_x * grid.spacing;
    // range to be queried to mandelbrot
    int query_rngx[2] = {0, size_x};
    int query_rngy[2] = {0, size_y};

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
    resolve_queries(
        data, size_x, size_y, 
        grid, query_rngx, query_rngy
    );
}


void shift_matrix(
    pixel_type * data,
    int size_x, int size_y,
    Grid & grid,
    int d_x, int d_y
) {
    if (d_x != 0) {
        horizontal_shift( data, size_x, size_y, grid, d_x );
    }
    if (d_y != 0) {
        vertical_shift( data, size_x, size_y, grid, d_y );
    }
}


void scale_matrix(
    pixel_type * data,
    int size_x, int size_y,
    Grid & grid,
    unsigned nom, unsigned denom
) {
    grid.spacing *= (pixel_type)denom;
    grid.spacing /= (pixel_type)nom;

    int query_rngx[2] = {0, size_x};
    int query_rngy[2] = {0, size_y};

    // time expensive mandelbrot queries
    resolve_queries(
        data, size_x, size_y, 
        grid, query_rngx, query_rngy
    );
}