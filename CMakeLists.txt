project(mandelbrot)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    lib/Backend/complex.cpp
    lib/Backend/image-processing.cpp
    lib/GUI/canvas.cpp
    lib/GUI/shapes.cpp
    lib/GUI/colormap.cpp
    main.cpp
)

add_executable(mandelbrot ${SOURCE_FILES})
include_directories(include)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(mandelbrot ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
