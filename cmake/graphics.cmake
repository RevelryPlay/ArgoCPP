find_package(OpenGL 3 REQUIRED)

# GLFW
add_subdirectory(external/GLFW)
target_include_directories(external_libs INTERFACE external/GLFW/include)
target_link_directories(external_libs INTERFACE external/GLFW/src)

#imgui
add_library(imgui_glfw STATIC
        external/imgui/imgui.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_demo.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/backends/imgui_impl_glfw.cpp
        external/imgui/backends/imgui_impl_opengl3.cpp
        )

target_link_libraries(imgui_glfw PUBLIC glfw ${OPENGL_LIBRARIES})

target_include_directories(imgui_glfw
        PUBLIC
        external/imgui
        external/imgui/backends
        external/imgui/examples
        )

target_link_libraries(external_libs INTERFACE
        glfw
        imgui_glfw)
