cmake_minimum_required(VERSION 3.24)
project(ArgoCPP VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. `-Wall` enable all compilation warnings
#set(CMAKE_CXX_FLAGS "-Wall")

# Update version number in source file
configure_file(ArgoConfig.h.in ArgoConfig.h)

# Include any project source files
file(GLOB CPP_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/**/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/**/**/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/**/**/*.hpp"
)

include_directories(${PROJECT_NAME}
        include
        include/Utilities
        )

add_executable(${PROJECT_NAME} ${CPP_SOURCES} ArgoConfig.h.in)

# Create an interface library to attach any external dependencies to
add_library(external_libs INTERFACE)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# Fetch submodules with git
include(cmake/git.cmake)

# Add any graphic utilities / libraries
include(cmake/graphics.cmake)

# Link our external libraries into ${PROJECT_NAME}
target_link_libraries(${PROJECT_NAME} PRIVATE external_libs)

# Run CTests
include(cmake/testing.cmake)
