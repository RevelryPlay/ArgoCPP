#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>

#include "ArgoConfig.h"

int main(int argc, char* argv[]) {
    std::cout << argv[0] << " - Version " << ARGO_VERSION_MAJOR
    << "." << ARGO_VERSION_MINOR << "."
    << ARGO_VERSION_PATCH << std::endl;

    GLFWwindow *window;

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(1024, 768, "New Window", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    std::cin.get();
}
