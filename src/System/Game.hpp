#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "Graphics/Window.hpp"

namespace Argo {
    class Game {
    public:
        Game();

        void Update();
        void LateUpdate();
        void Draw();
        bool IsRunning();

    private:
        Window* window;
    };
}
