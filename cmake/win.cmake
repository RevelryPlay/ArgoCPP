# Add any graphic utilities / libraries
include(cmake/graphics.cmake)

# Copy image resource files
file(GLOB IMG_SRC resources/images/**.png)
file(COPY ${IMG_SRC} DESTINATION ${CMAKE_BINARY_DIR}/resources/images)
