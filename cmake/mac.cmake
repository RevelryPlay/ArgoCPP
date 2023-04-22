include(cmake/mac-graphics.cmake)

target_link_libraries(${PROJECT_NAME} PUBLIC
        "-framework Foundation"
        "-framework IOKit"
        "-framework QuartzCore"
        "-framework Metal"
)
