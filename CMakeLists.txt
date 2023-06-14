cmake_minimum_required(VERSION 3.24)

# Only set the cxx_standard if it is not set by someone else
if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED True)

# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

project(
        ArgoCpp
        VERSION 0.0.1
        DESCRIPTION "Argo game engine written in C++"
        HOMEPAGE_URL "https://www.revelryplay.com/Projects/Argo/"
        LANGUAGES CXX C
)

# 1. `-Wall` enable all compilation warnings
#set(CMAKE_CXX_FLAGS "-Wall")

# Update version number in source file
configure_file(ArgoConfig.h.in ArgoConfig.h ESCAPE_QUOTES)

# Include any project source files
file(GLOB_RECURSE COMMON_CPP_SOURCES
        "${PROJECT_SOURCE_DIR}/src/Common/main.cpp"
        "${PROJECT_SOURCE_DIR}/src/Common/**/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Common/**/*.hpp"
        )

file(GLOB_RECURSE WIN_CPP_SOURCES
        "${PROJECT_SOURCE_DIR}/src/Windows/**/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Windows/**/*.hpp"
        )

file(GLOB_RECURSE MAC_CPP_SOURCES
        "${PROJECT_SOURCE_DIR}/src/Mac/**/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Mac/**/*.hpp"
        )

if (WIN32)
    set(CPP_SOURCES ${COMMON_CPP_SOURCES} ${WIN_CPP_SOURCES})
elseif (APPLE)
    set(CPP_SOURCES ${COMMON_CPP_SOURCES} ${MAC_CPP_SOURCES})
endif ()

add_executable(${PROJECT_NAME} ${CPP_SOURCES} ArgoConfig.h.in)

# Create an interface library to attach any external dependencies to
add_library(external_libs INTERFACE)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# Fetch submodules with git
include(cmake/git.cmake)

# Any extra OS specific configuration
if (WIN32)
    include(cmake/win.cmake)
elseif (APPLE)
    include(cmake/mac.cmake)
endif ()

# Robin Hood
add_subdirectory(external/robin-hood)
target_include_directories(external_libs INTERFACE external/robin-hood/src/include)

# Link our external libraries into ${PROJECT_NAME}
target_link_libraries(${PROJECT_NAME} PUBLIC external_libs)

# Run CTests
#include(cmake/testing.cmake)
