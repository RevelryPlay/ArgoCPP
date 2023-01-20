#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Window.hpp"
#include "Vec4.hpp"

namespace Argo  {

    class WindowImGUI : public Window {
    public:
        WindowImGUI();
        WindowImGUI(int width, int height, const char *title);
        ~WindowImGUI();

        void Update();
        void RenderFrame();
        void Close();
        bool IsOpen();

    protected:
        void CreateDockSpace();
        Argo::Utilities::Vec4 clearColorVec4 = Argo::Utilities::CommonColor().ToVec4();
    };
}
