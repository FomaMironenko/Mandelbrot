#include <iostream>
#include <GLUT/glut.h>

#include "Backend/complex.h"

using d_type = complex::data_type;
using i_type = complex::iter_type;

int main(int argc, char** argv) {

    d_type re, im;

    std::cin >> re >> im;

    std::cout << (int)complex::belonging_rate(re, im) << std::endl;

    return EXIT_SUCCESS;
}