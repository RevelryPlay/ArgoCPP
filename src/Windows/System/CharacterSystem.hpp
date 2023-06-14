#pragma once
#include "../../Common/Common.hpp"
#include "Graphics/OpenGL/Camera.hpp"
#include "Game.hpp"
#include "Input.hpp"
#include "CharacterController.hpp"

namespace Argo {
    struct Camera;
    struct CharacterController;
    struct Rigidbody;

    namespace CharacterSystem
    {
        void update(CharacterController& controller, Camera& camera, Rigidbody& rb);
    }
}
