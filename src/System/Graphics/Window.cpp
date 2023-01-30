#pragma once

#include "Window.hpp"
#include "ColorConverter.hpp"

#include "Image.hpp"

namespace Argo {
    Window::Window() {
        Window(800, 600, "");
    }

    Window::Window(double width, double height, const char *title) {
        /* Initialize the library */
        if (!glfwInit())
            return;

        glfwSetTime(0);

        this->width = &width;
        this->height = &height;

        /* Create a windowed mode window and its OpenGL context */
        this->window = glfwCreateWindow(width, height, title, NULL, NULL);
        this->clearColor = Utilities::ConvertColor(0x1f7fbfff);

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
            Close();
            return;
        }

        RenderFrame();
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

            glOrtho(0, *this->width, 0, *this->height, -1, 1);


//            Image* image = new Image("resources/viking.png");





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

    Window::~Window() {
        Close();
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
}
