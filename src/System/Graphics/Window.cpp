#pragma once

#include "Window.hpp"
#include "ColorConverter.hpp"

#include "Image.hpp"

namespace Argo {
    static Shader shader;

    struct Vertex {
        std::array<float, 4> color;
        std::array<float, 3> position;
    };

    static std::array<Vertex, 6> colorSquares = {
            //      Color                         Position
            Vertex{{0.9f,  0.1f, 0.12f, 1.0f},   {-0.5f, -0.5f, 0.0f}},
            Vertex{{0.1f,  0.9f, 0.12f, 1.0f},   {-0.5f,  0.5f, 0.0f}},
            Vertex{{0.12f, 0.9f, 0.1f,  1.0f},   { 0.5f,  0.5f, 0.0f}},

            Vertex{{0.9f,  0.1f, 0.12f, 1.0f},   {-0.5f, -0.5f, 0.0f}},
            Vertex{{0.12f, 0.9f, 0.1f,  1.0f},   { 0.5f,  0.5f, 0.0f}},
            Vertex{{0.12f, 0.1f, 0.9f,  1.0f},   { 0.5f, -0.5f, 0.0f}}
    };

    static uint32_t colorSquaresVAO;
    static uint32_t colorSquaresVBO;

    void setupColorSquaresTest()
    {
        glCreateVertexArrays(1, &colorSquaresVAO);
        glBindVertexArray(colorSquaresVAO);

        glGenBuffers(1, &colorSquaresVBO);
        glBindBuffer(GL_ARRAY_BUFFER, colorSquaresVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colorSquares), colorSquares.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        glEnableVertexAttribArray(1);
    }

    void drawColorSquaresTest()
    {
        glBindVertexArray(colorSquaresVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    void destroyColorSquaresTest()
    {
        glDeleteBuffers(1, &colorSquaresVBO);
        glDeleteVertexArrays(1, &colorSquaresVAO);
    }

    void Window::KeyHandler(GLFWwindow *window,
                            int key,
                            [[maybe_unused]] int scancode,
                            int action,
                            [[maybe_unused]] int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }

    Window::Window() {
        Window(800, 600, "", false);
    }

    Window::Window(int initial_width, int initial_height, const char *title, bool fullscreen) {
        /* Initialize the GLFW library */
        if (!glfwInit()) {
            return;
        }

        glfwSetTime(0);

        width = initial_width;
        height = initial_height;

        /* Create a windowed mode window and its OpenGL context */
        GLFWmonitor* primaryMonitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;
        window = glfwCreateWindow(width, height, title, primaryMonitor, nullptr);
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

        shader.Compile();

        glViewport(0, 0, width, height);

        shader.Bind();

        glfwSetKeyCallback(window, KeyHandler);

        setupColorSquaresTest();

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



            drawColorSquaresTest();




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

        destroyColorSquaresTest();

        glfwTerminate();
        window = nullptr;
    }

    bool Window::IsOpen() {
        return window != nullptr;
    }
}
