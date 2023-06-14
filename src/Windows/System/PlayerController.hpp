#pragma once
#include "../../Common/Common.hpp"
#include "Input.hpp"
#include "Game.hpp"
#include "Graphics/OpenGL/Window.hpp"
#include "CharacterController.hpp"

namespace Argo {
    struct CharacterController;

    namespace PlayerController
    {
        void update(CharacterController& controller);
    }
}
