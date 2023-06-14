#ifndef ARGOCPP_COMMON_HPP
#define ARGOCPP_COMMON_HPP

// STD
#include <array>
#include <cassert>
#include <fstream>
#include <filesystem>
#include <format>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <map>

// GLM
#define GLM_EXT_INCLUDED
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/hash.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/matrix.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/integer.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_access.hpp>

// Robin Hood
#include <robin_hood.h>

// Windows Specific Code
#ifdef _WIN32
    #define GLFW_INCLUDE_NONE
    #include <GLFW/glfw3.h>

    #include <glad/gl.h>
#endif

// Mac OS Specific Code
#if defined(__APPLE__) && defined(__MACH__)
    // Metal
    #define NS_PRIVATE_IMPLEMENTATION
    #define MTL_PRIVATE_IMPLEMENTATION
    #define MTK_PRIVATE_IMPLEMENTATION
    #define CA_PRIVATE_IMPLEMENTATION
    // These should really be used as libraries
    #include "Foundation/Foundation.hpp"
    #include "Metal/Metal.hpp"
    #include "QuartzCore/QuartzCore.hpp"
    #include "AppKit/AppKit.hpp"
    #include "MetalKit/MetalKit.hpp"

    // GLFW
    #define GLFW_INCLUDE_NONE
    #define GLFW_EXPOSE_NATIVE_COCOA
    #include <GLFW/glfw3.h>
    #include <GLFW/glfw3native.h>

    // IMGUI
    #include "imgui.h"
    #include "imgui_impl_glfw.h"
    #include "imgui_impl_metal.h"
#endif

#endif
