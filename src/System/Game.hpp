#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "Graphics/WindowImGUI.hpp"

namespace Argo {
    class Game {
    public:
        Game();

        void Update();
        void LateUpdate();
        void Draw();
        bool IsRunning();
        void Close();

    private:
        WindowImGUI* window;
    };
}
