cmake_minimum_required(VERSION 3.15)
project(my_project)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0

set(CMAKE_C_STANDARD 11) # Requires C11 standard

add_executable(${PROJECT_NAME} main.cpp)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    # Sources
    src/company.cpp
    src/days.cpp
    src/engine.cpp

    #Headers
    src/camera.hpp
    src/company.hpp
    src/days.hpp
    src/engine.hpp
    )

target_link_libraries(${PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
