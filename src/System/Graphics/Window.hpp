#ifndef ARGOCPP_WINDOW_HPP
#define ARGOCPP_WINDOW_HPP

#include <iostream>
#include "CommonColor.hpp"

class Window {
public:
    int Init(int width, int height, const char *title);
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
    CommonColor clearColor = CommonColor();
};

#endif //ARGOCPP_WINDOW_HPP
