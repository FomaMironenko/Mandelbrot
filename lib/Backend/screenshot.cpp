
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <ctime>

#include <vector>

#include "Backend/complex.h"
#include "Backend/screenshot.h"
#include "GUI/canvas.h"
#include "GUI/colormap.h"


void capture_screenshot(
    const Grid & grid
) {
    Grid scr_grid{grid};
    scr_grid.spacing *= (coord_type) size_x / (coord_type) scr_size_x;

    std::vector<pixel_type> scr_data(scr_size_x * scr_size_y);
    std::vector<pixel_type> scr_picture(scr_size_x * scr_size_y * 3);
    int query_rngx[2] = {0, scr_size_x};
    int query_rngy[2] = {0, scr_size_y};

    resolve_queries(
        scr_data.data(), scr_size_x, scr_size_y, 
        scr_grid, query_rngx, query_rngy
    );
    apply_colormap(
        scr_picture.data(), scr_data.data(),
        scr_size_x, scr_size_y
    );

    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::stringstream sstr;
    sstr << "pic_" << std::put_time(&tm, "%Y_%m_%d_%H%M%S") << ".ppm";

    auto base_path = std::filesystem::current_path();
    base_path /= "screenshots";
    std::filesystem::create_directories(base_path);
    auto file_path = base_path / sstr.str();

    std::ofstream file(file_path);
    file << "P3\n";
    file << scr_size_x << " " << scr_size_y << "\n";
    file << "pixels\n";
    file << 255 << "\n";
    for (int i = 0; i < scr_size_x * scr_size_y; i++) {
        file << (int)scr_picture[i*3 + 0] << " "
             << (int)scr_picture[i*3 + 1] << " "
             << (int)scr_picture[i*3 + 2] << "\n";
    }
    file.close();
}