#ifndef ARGOCPP_GAME_HPP
#define ARGOCPP_GAME_HPP

#include <GLFW/glfw3.h>
#include <iostream>

#include "Graphics/Window.hpp"

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

#endif //ARGOCPP_GAME_HPP
