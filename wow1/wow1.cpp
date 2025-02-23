#include "GL\glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

#define GLEW_DLL
#define GLFW_DLL


int main() {

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW.\n");
        return 1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   //  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(700, 700, "meow_beautiful_triangle_1_11", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(ret));
        return 1;
    }
    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0, 0.2, 0.3, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 0.5); 
        glVertex2f(-0.5, -0.5); 
        glVertex2f(0.5, -0.5); 

        glColor3f(0.4, 1.0, 0.4);

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}