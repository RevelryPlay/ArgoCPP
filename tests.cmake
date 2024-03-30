# Testing
include(CTest)

if (BUILD_TESTING)
    find_package(PkgConfig)
    find_package(GTest CONFIG REQUIRED)

    add_executable(${PROJECT_NAME}-tests)

    # NOTE: Will probably make this use a glob to build the list of files in the future
    # Additionally will make this use the graphics pipeline conditionals to filter out the unused files

    target_sources(${PROJECT_NAME}-tests PRIVATE
            Core/ArgoProject.cpp Core/include/ArgoProject.hpp
            Core/ArgoProjectTests.cpp

            Core/Types/CommonColor.cpp Core/include/Types/CommonColor.hpp
            Core/include/Types/Vec4.hpp

            Utilities/ColorConverter.cpp Utilities/include/ColorConverter.hpp
            Utilities/ColorConverterTests.cpp
    )

    target_include_directories(${PROJECT_NAME}-tests PUBLIC ${PROJECT_BINARY_DIR})

#    target_compile_definitions(${PROJECT_NAME}-tests PRIVATE OPTS_USE_OPENGL)

#    find_package(OpenGL REQUIRED)
#    target_link_libraries(${PROJECT_NAME}-tests PRIVATE OpenGL::GL)
#
#    find_package(glad CONFIG REQUIRED)
#    target_link_libraries(${PROJECT_NAME}-tests PRIVATE glad::glad)
#
#    find_package(glfw3 CONFIG REQUIRED)
#    target_link_libraries(${PROJECT_NAME}-tests PRIVATE glfw)
#
#    find_package(glm CONFIG REQUIRED)
#    target_link_libraries(${PROJECT_NAME}-tests PRIVATE glm::glm)

    enable_testing()

    target_link_libraries(${PROJECT_NAME}-tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    target_compile_options(${PROJECT_NAME}-tests PRIVATE ${GTEST_CFLAGS})

    include(GoogleTest)

    gtest_discover_tests(${PROJECT_NAME}-tests)
endif ()
