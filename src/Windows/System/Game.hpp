#pragma once

#include "glm/mat4x4.hpp"
#include "glm/matrix.hpp"

#include "Common.hpp"
#include "Graphics/OpenGL/Window.hpp"
#include "Cubes.hpp"
#include "Input.hpp"
#include "CharacterController.hpp"
#include "CharacterSystem.hpp"
#include "PlayerController.hpp"
#include "Graphics/OpenGL/Camera.hpp"

namespace Argo {
    struct Window;

    namespace Game
    {
        bool init();
        void run();
        void free();

        const Window& getWindow();

        extern float deltaTime;
    }
}
