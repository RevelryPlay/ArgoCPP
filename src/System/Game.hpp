#pragma once

#include <iostream>
#include "Graphics/Window.hpp"
//#include "Graphics/WindowImGUI.hpp"

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
        Window *window;
//        WindowImGUI* window;
    };
}
