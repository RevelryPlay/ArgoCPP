cmake_minimum_required(VERSION 3.24)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
        ArgoGraphics
        VERSION 0.0.1.0
        DESCRIPTION "Graphics Module of the Argo game engine"
        HOMEPAGE_URL "https://www.revelryplay.com/Projects/Argo/"
        LANGUAGES CXX C
)


# Graphics pipeline
# In the future multiple pipelines will be available,
# for now only enable one of these options at a time

SET(OPTS_USE_OPENGL ON) # Basic structure exists for 0.0.1; API incomplete
SET(OPTS_USE_VULKAN OFF) # Incomplete
# SET(USE_METAL OFF) # Not present at this time
# SET(USE_DX OFF) # Not present at this time

# Slint UI
SET(OPTS_USE_SLINT OFF) # Prototype UI

# End of current options


# Force one and only one of the pipelines to be active
# This is temporary as there will also be a console only pipeline and the ability to have multiple pipelines active is planned
if ((NOT OPTS_USE_OPENGL AND NOT OPTS_USE_VULKAN) OR
(OPTS_USE_OPENGL AND OPTS_USE_VULKAN))
    SET(OPTS_USE_OPENGL ON)
    SET(OPTS_USE_VULKAN OFF)
endif ()

add_library(
        ${PROJECT_NAME} STATIC
)

TARGET_SOURCES(
        ${PROJECT_NAME} PRIVATE
        include/Renderer.hpp
)

if (OPTS_USE_OPENGL)
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

    find_package(glad CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

    find_package(glfw3 CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

    find_package(glm CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

    find_package(imgui CONFIG REQUIRED)
    target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)

    find_package(Stb REQUIRED)
    target_include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})

    TARGET_SOURCES(
            ${PROJECT_NAME} PRIVATE
            OpenGL/Renderer.cpp
    )
endif ()

if (OPTS_USE_VULKAN)
    target_compile_definitions(${PROJECT_NAME} PRIVATE OPTS_USE_VULKAN)

    TARGET_SOURCES(
            ${PROJECT_NAME} PRIVATE
            Vulkan/Renderer.cpp
    )
endif ()

if (OPTS_USE_SLINT)
    target_compile_definitions(${PROJECT_NAME} PRIVATE OPTS_USE_SLINT)

    TARGET_SOURCES(
            ${PROJECT_NAME} PRIVATE
            SlintUI/Renderer.cpp
    )

    include(FetchContent)
    FetchContent_Declare(
            Slint
            GIT_REPOSITORY https://github.com/slint-ui/slint.git
            # `release/1` will auto-upgrade to the latest Slint >= 1.0.0 and < 2.0.0
            # `release/1.0` will auto-upgrade to the latest Slint >= 1.0.0 and < 1.1.0
            GIT_TAG release/1
            SOURCE_SUBDIR api/cpp
    )
    FetchContent_MakeAvailable(Slint)

    target_link_libraries(${PROJECT_NAME} PRIVATE Slint::Slint)
    slint_target_sources(${PROJECT_NAME}
            SlintUI/MainWindow.slint
            SlintUI/GLWindow.slint
            NAMESPACE Argo::Graphics)
    # On Windows, copy the Slint DLL next to the application binary so that it's found.
    #    if (WIN32)
    #        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND}
    #                -E copy $<TARGET_RUNTIME_DLLS:argo-graphics> $<TARGET_FILE_DIR:argo-graphics> COMMAND_EXPAND_LISTS)
    #    endif ()
endif ()
