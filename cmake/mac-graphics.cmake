# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/GLFW)
target_include_directories(external_libs INTERFACE external/GLFW/include)
target_link_directories(external_libs INTERFACE external/GLFW/src)

# stb_image library
target_include_directories(external_libs INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/external/stb)

#imgui
add_library(imgui_glfw STATIC
        external/imgui/imgui.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_demo.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imgui_tables.cpp
        )

target_link_libraries(imgui_glfw PUBLIC glfw ${OPENGL_LIBRARIES})

target_include_directories(imgui_glfw
        PUBLIC
        external/imgui
        external/imgui/backends
        external/imgui/examples
        external/metal-cpp
        external/metal-cpp-extensions
        )

# GLM
add_subdirectory(external/glm)

target_link_libraries(
        external_libs INTERFACE
        glfw
        imgui_glfw
        glm
)
