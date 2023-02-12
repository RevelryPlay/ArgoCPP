#pragma once

#include <iostream>

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "CommonColor.hpp"

namespace Argo {
    class Window {
    public:
        Window();
        Window(double width, double height, const char *title);
        ~Window();

        static void KeyHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
        void Update();
        void RenderFrame();
        void Close();
        bool IsOpen();
        int GetFPS();

    protected:
        GLFWwindow* window;
        double* width;
        double* height;
        int frameRateCap = 120;
        int drawFrameCount = 0;
        double lastFrameTime;
        double lastFPSTime;
        Argo::Utilities::CommonColor clearColor = Argo::Utilities::CommonColor();
    };
}
