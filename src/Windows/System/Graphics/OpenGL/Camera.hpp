#pragma once

#include "../../../../Common/Common.hpp"
#include "../../Game.hpp"

namespace Argo {
    struct Camera {
        glm::vec3 position;
        glm::quat orientation;

        glm::vec3 forward;
        glm::vec3 right;
        glm::vec3 up;
        glm::mat4 projection;
        glm::mat4 view;
        float fov;

        const glm::mat4& calculateViewMatrix();
        const glm::mat4& calculateProjectionMatrix();
    };
}
