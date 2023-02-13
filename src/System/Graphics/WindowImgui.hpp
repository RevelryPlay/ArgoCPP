#pragma once

#include <iostream>

#define GLFW_INCLUDE_NONE

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <glm/vec4.hpp>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Window.hpp"

namespace Argo {

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

        glm::vec4 clearColorVec4 = Argo::Utilities::CommonColor().ToVec4();
    };
}
