#ifndef SCREENSHOT
#define SCREENSHOT


#include <Backend/image-processing.h>

constexpr int scr_size_x = 720 * 4;
constexpr int scr_size_y = 480 * 4;

void capture_screenshot(
    const Grid & grid
);

#endif
