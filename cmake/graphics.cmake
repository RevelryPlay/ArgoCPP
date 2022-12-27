find_package(OpenGL 3 REQUIRED)

# GLFW
add_subdirectory(lib/GLFW)
target_include_directories(external_libs INTERFACE lib/GLFW/include)
target_link_directories(external_libs INTERFACE lib/GLFW/src)

#imgui
add_library(imgui_glfw STATIC
        lib/imgui/imgui.cpp
        lib/imgui/imgui_draw.cpp
        lib/imgui/imgui_demo.cpp
        lib/imgui/imgui_widgets.cpp
        lib/imgui/imgui_tables.cpp
        lib/imgui/backends/imgui_impl_glfw.cpp
        lib/imgui/backends/imgui_impl_opengl3.cpp
        )

target_link_libraries(imgui_glfw PUBLIC glfw ${OPENGL_LIBRARIES})

target_include_directories(imgui_glfw
        PUBLIC
        lib/imgui
        lib/imgui/backends
        lib/imgui/examples
        )

target_link_libraries(external_libs INTERFACE
        glfw
        imgui_glfw)
