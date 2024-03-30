cmake_minimum_required(VERSION 3.24)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
        ArgoCore
        VERSION 0.0.1.0
        DESCRIPTION "Core Module of the Argo game engine"
        HOMEPAGE_URL "https://www.revelryplay.com/Projects/Argo/"
        LANGUAGES CXX C
)

add_library(
        ${PROJECT_NAME} STATIC
        ArgoProject.cpp include/ArgoProject.hpp

        Types/CommonColor.cpp include/Types/CommonColor.hpp
        include/Types/Vec4.hpp
        include/Types/Vertex.hpp
)

include(tests.cmake)
