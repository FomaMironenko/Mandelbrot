#ifndef EMIT_OPENGL
#define EMIT_OPENGL

// glut.h
#if __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

// gl.h
#if __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif


#endif //EMIT_OPENGL
