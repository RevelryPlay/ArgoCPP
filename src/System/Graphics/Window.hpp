#ifndef ARGOCPP_WINDOW_HPP
#define ARGOCPP_WINDOW_HPP

#include <iostream>

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


};

#endif //ARGOCPP_WINDOW_HPP
