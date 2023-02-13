#pragma once

#include "Window.hpp"
#include "ColorConverter.hpp"

#include "Image.hpp"

namespace Argo {
    void Window::KeyHandler(GLFWwindow *window,
                            int key,
                            [[maybe_unused]] int scancode,
                            int action,
                            [[maybe_unused]] int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, 1);
        }
    }

    Window::Window() {
        Window(800, 600, "");
    }

    Window::Window(int initial_width, int initial_height, const char *title) {
        /* Initialize the GLFW library */
        if (!glfwInit()) {
            return;
        }

        glfwSetTime(0);

        width = initial_width;
        height = initial_height;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        clearColor = Utilities::ConvertColor(0x1f7fbfff);

        if (!window) {
            glfwTerminate();
            return;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Load glad */
        int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0) {
            fprintf(stderr, "Failed to initialize OpenGL context\n");
            return;
        }

        glViewport(0, 0, width, height);

        glfwSetKeyCallback(window, KeyHandler);
    }

    void Window::Update() {
        if (!window) {
            return;
        }

        if (glfwWindowShouldClose(window)) {
            Close();
            return;
        }

        RenderFrame();

        /* Poll for and process events */
        glfwPollEvents();
    }

// This will limit render calls to a defined framerate
    void Window::RenderFrame() {
        double currentTime = glfwGetTime();
        double delta = currentTime - lastFrameTime;

        if (delta >= (1.0 / this->frameRateCap)) {
            lastFrameTime = currentTime;
            drawFrameCount++;

            /* Render here */
            glClearColor(clearColor.red,
                         clearColor.green,
                         clearColor.blue,
                         clearColor.alpha);

            glClear(GL_COLOR_BUFFER_BIT);

//            glOrtho(0, *this->width, 0, *this->height, -1, 1);
//            Image* image = new Image("resources/viking.png");

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

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

    Window::~Window() {
        Close();
    }

    void Window::Close() {
        if (!window) {
            return;
        }

        glfwTerminate();
        window = nullptr;
    }

    bool Window::IsOpen() {
        return window != nullptr;
    }
}
