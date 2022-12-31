include(CTest)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    file(GLOB CPP_TEST_SOURCES
        "${PROJECT_SOURCE_DIR}/include/Utilities/**.tests.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.tests.cpp"
        "${PROJECT_SOURCE_DIR}/src/**/*.tests.cpp"
    )

    add_executable(${PROJECT_NAME}-tests ${CPP_TEST_SOURCES})
    include_directories(${PROJECT_NAME}-tests
            include
            include/Utilities
            )

    add_subdirectory(external/googletest)
    
    target_link_libraries(${PROJECT_NAME}-tests PRIVATE GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(${PROJECT_NAME}-tests)
endif()
