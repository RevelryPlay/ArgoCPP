#pragma once
#include "CommonIncludes.hpp"

namespace Argo {
    struct CharacterController
    {
        float controllerBaseSpeed;
        float controllerRunSpeed;
        float movementSensitivity;

        glm::vec3 movementAxis;
        glm::vec3 viewAxis;
        bool isRunning;
        bool lockedToCamera;
    };

    // TODO: Move this into physics library once it gets created
    struct Rigidbody
    {
        glm::vec3 velocity;
        glm::vec3 acceleration;
        float friction;
    };
}
