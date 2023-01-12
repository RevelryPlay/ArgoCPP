#include <GLFW/glfw3.h>
#include "Window.hpp"
#include "ColorConverter.hpp"

Window::Window(int width, int height, const char *title) {
    /* Initialize the library */
    if (!glfwInit())
        return;

    glfwSetTime(0);

    /* Create a windowed mode window and its OpenGL context */
    this->window = glfwCreateWindow(width, height, title, NULL, NULL);
    this->clearColor = ConvertColor(0x1f7fbfff);

    if (!this->window) {
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(this->window);
}

void Window::Update() {
    if (!this->window) {
        return;
    }

    if (glfwWindowShouldClose(this->window)) {
        this->Close();
        return;
    }

    this->RenderFrame();
}

// This will limit render calls to a defined framerate
void Window::RenderFrame() {
    double currentTime = glfwGetTime();
    double delta = currentTime - this->lastFrameTime;

    if (delta >= (1.0 / this->frameRateCap)) {
        this->lastFrameTime = currentTime;
        this->drawFrameCount++;

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glClearColor(this->clearColor.red,
                     this->clearColor.green,
                     this->clearColor.blue,
                     this->clearColor.alpha);

        /* Swap front and back buffers */
        glfwSwapBuffers(this->window);

        /* Poll for and process events */
        glfwPollEvents();

        return;
    }
}

int Window::GetFPS() {
    double currentTime = glfwGetTime();

    if (currentTime - lastFPSTime >= 1.0) {
        lastFPSTime = currentTime;

        fprintf(stdout, "FPS: %d - Frame Limit: %d\r\n",
                drawFrameCount,
                frameRateCap);

        drawFrameCount = 0;
    }

    return drawFrameCount;
}

void Window::Close() {
    if (!this->window) {
        return;
    }

    glfwTerminate();
    this->window = nullptr;
}

bool Window::IsOpen() {
    return this->window != nullptr;
}
