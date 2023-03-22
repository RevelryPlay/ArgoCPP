#pragma once
#include "CommonIncludes.hpp"

namespace Argo {
    struct Window {
        GLFWwindow* nativeWindow;
        int windowWidth;
        int windowHeight;

        void installMainCallbacks();

        void close();

        inline float getAspectRatio() const {
            return (float)windowWidth / (float)windowHeight;
        }

        static Window* createWindow(int width, int height, const char* title, bool fullScreenMode=false);
        static void freeWindow(Window* window);
    };
}
