project(mandelbrot)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    lib/Backend/complex.cpp
    main.cpp)

add_executable(mandelbrot ${SOURCE_FILES})

include_directories(include)
