cmake_minimum_required(VERSION 3.16)
project(circle_simulation)

# ------------------------------------------------------------------------------
# C++ Standard and Build Settings
# ------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# If no build type is specified, default to Debug.
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type specified, defaulting to Debug")
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

# ------------------------------------------------------------------------------
# Options for External Dependencies
# ------------------------------------------------------------------------------
# Disable Wayland support for GLFW
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Disable Wayland support" FORCE)

# ------------------------------------------------------------------------------
# External Dependencies: FetchContent Setup for GLFW
# ------------------------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        latest
)
FetchContent_MakeAvailable(glfw)

# ------------------------------------------------------------------------------
# Target Definition
# ------------------------------------------------------------------------------
set(TARGET_EXECUTABLE ${PROJECT_NAME})
add_executable(${TARGET_EXECUTABLE}
    circle_simulation/main.cpp
    circle_simulation/cli.cpp
    circle_simulation/simulation.cpp
    circle_simulation/window.cpp
    circle_simulation/renderer.cpp
    circle_simulation/circle.cpp
    circle_simulation/world.cpp
)

# ------------------------------------------------------------------------------
# Target Compile Options, Libraries, and Includes
# ------------------------------------------------------------------------------
target_compile_options(${TARGET_EXECUTABLE} PRIVATE -Wall -Wextra -Werror)
target_link_libraries(${TARGET_EXECUTABLE} PRIVATE glfw GL)
target_include_directories(${TARGET_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR})

# ------------------------------------------------------------------------------
# Build Configuration Specific Flags
# ------------------------------------------------------------------------------
if(CMAKE_BUILD_TYPE STREQUAL "Release")
  message(STATUS "Configuring Release build settings")
  target_compile_definitions(${TARGET_EXECUTABLE} PRIVATE NDEBUG)
  target_compile_options(${TARGET_EXECUTABLE} PRIVATE -O3 -march=native -flto)
endif()