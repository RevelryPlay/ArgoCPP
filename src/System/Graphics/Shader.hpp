#pragma once

#define GLFW_INCLUDE_NONE

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/integer.hpp>

namespace Argo {
    struct Shader
    {
        uint32_t ProgramId;

        void Compile();
        void Bind();

    };
}
