#pragma once

#include "CommonIncludes.hpp"
#include "Graphics/OpenGL/Camera.hpp"
#include "Graphics/OpenGL/ShaderProgram.hpp"

namespace Argo {
    struct Window;
    struct Camera;

    namespace Cubes
    {
        void init();
        void destroy();

        void update(const Camera& camera);
    }
}
