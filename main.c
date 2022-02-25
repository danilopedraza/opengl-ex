#include <stdio.h>
#include <stdlib.h> // put before to avoid visual studio bug (in windows)
#include <GL/glew.h>
#ifdef __APPLE__
#   include <GLUT/glut.h>
#else
#   include <GL/glut.h>
#endif

static int make_resources(void) {
    return 1;
}

static void update_fade_factor(void) {}

static void render(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Hello, World!");
    glutDisplayFunc(&render);
    glutIdleFunc(&update_fade_factor);

    glewInit();
    if (!GLEW_VERSION_2_0) {
        fprintf(stderr, "OpenGL 2.0 not available\n");
        return 1;
    }

    if (!make_resources()) {
        fprintf(stderr, "Failed to load resources\n");
        return 1;
    }

    glutMainLoop();

    return 0; // never reached
}


/*
compile (in linux) with:
gcc -o main main.c \
    -I/usr/X11R6/include -L/usr/X11R6/lib \
    -lGL -lGLEW -lglut
*/
