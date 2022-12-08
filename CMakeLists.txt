cmake_minimum_required(VERSION 3.24)
project(ArgoCPP VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. `-Wall` enable all compilation warnings
#set(CMAKE_CXX_FLAGS "-Wall")

configure_file(ArgoConfig.h.in ArgoConfig.h)

file(GLOB CPP_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
)

add_executable(${PROJECT_NAME} ${CPP_SOURCES} ArgoConfig.h.in)

# Create an interface library to attach any external dependencies to
add_library(external_libs INTERFACE)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(WARNING "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}. You may need to checkout submodules manually.")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/lib/GLFW/CMakeLists.txt")
    message(FATAL_ERROR "The GLFW submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

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
        ${CMAKE_CURRENT_LIST_DIR}/lib/imgui
        ${CMAKE_CURRENT_LIST_DIR}/lib/imgui/backends
        ${CMAKE_CURRENT_LIST_DIR}/lib/imgui/examples
        )

target_link_libraries(external_libs INTERFACE
        glfw
        imgui_glfw)

# Link our external libraries into ${PROJECT_NAME}
target_link_libraries(${PROJECT_NAME} PRIVATE external_libs)
