#pragma once

#include <iostream>
#include "CommonColor.hpp"

namespace Argo {
    class Window {
    public:
        Window(int width, int height, const char *title);
        void Update();
        void RenderFrame();
        void Close();
        bool IsOpen();
        int GetFPS();
    private:
        GLFWwindow* window;
        int frameRateCap = 120;
        int drawFrameCount = 0;
        double lastFrameTime;
        double lastFPSTime;
        Argo::Utilities::CommonColor clearColor = Argo::Utilities::CommonColor();
    };
}
