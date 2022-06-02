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
if (APPLE)
    message(STATUS "linking OpenGL [GLUT] for MacOS")
    find_package(GLUT REQUIRED)
else ()
    message(STATUS "linking OpenGL [GL] for Win of Linux")
    find_package(GL REQUIRED)
endif()

if (OPENGL_FOUND)
    message(STATUS "OpenGL successfully linked")
else()
    message(FATAL_ERROR "OpenGL not found")
endif()

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(mandelbrot ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
