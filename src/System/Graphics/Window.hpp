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

        Window(int width, int height, const char *title);

        ~Window();

        static void KeyHandler(
                [[maybe_unused]] GLFWwindow *window,
                int key, [[maybe_unused]]
                int scancode,
                int action,
                int mods
        );

        void Update();

        void RenderFrame();

        void Close();

        bool IsOpen();

        int GetFPS();

    protected:
        GLFWwindow *window = nullptr;
        int width = 0;
        int height = 0;
        int frameRateCap = 120;
        int drawFrameCount = 0;
        double lastFrameTime = 0;
        double lastFPSTime = 0;
        Argo::Utilities::CommonColor clearColor = Argo::Utilities::CommonColor();
    };
}
