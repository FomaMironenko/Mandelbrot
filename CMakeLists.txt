project(mandelbrot)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    lib/Backend/complex.cpp
    lib/GUI/canvas.cpp
    main.cpp
)

add_executable(mandelbrot ${SOURCE_FILES})
include_directories(include)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(mandelbrot ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
