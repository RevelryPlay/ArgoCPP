find_package(OpenGL 3 REQUIRED)

# GLFW
add_subdirectory(external/GLFW)
target_include_directories(external_libs INTERFACE external/GLFW/include)
target_link_directories(external_libs INTERFACE external/GLFW/src)

# glad
set(GLAD_SOURCES_DIR "${PROJECT_SOURCE_DIR}/external/glad/")
add_subdirectory("${GLAD_SOURCES_DIR}/cmake" glad_cmake)
glad_add_library(glad_gl_core_33 REPRODUCIBLE API gl:core=3.3)


# stb_image library
target_include_directories(external_libs INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/external/stb)

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

target_link_libraries(
        external_libs INTERFACE
        glad_gl_core_33
        glfw
        imgui_glfw
)

# Copy image resource files
file(GLOB IMG_SRC resources/**.png)
file(COPY ${IMG_SRC} DESTINATION ${CMAKE_BINARY_DIR}/resources)
