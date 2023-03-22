#pragma once

#include "CommonIncludes.hpp"

namespace Argo {
    enum class ShaderType : uint8_t
    {
        Vertex,
        Fragment,
    };

    struct Shader
    {
        char* filepath;
        uint32_t shaderId;
        ShaderType type;

        bool compile(ShaderType type, const char* shaderFilepath);
        void destroy();

        static GLenum toGlShaderType(ShaderType type);
    };
}
