cmake_minimum_required(VERSION 3.24)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
        ArgoAudio
        VERSION 0.0.1.0
        DESCRIPTION "Audio Module of the Argo game engine"
        HOMEPAGE_URL "https://www.revelryplay.com/Projects/Argo/"
        LANGUAGES CXX C
)

add_library(
        ${PROJECT_NAME} STATIC
)
