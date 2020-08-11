cmake_minimum_required(VERSION 3.0)
project(BuildGame)

set(CMAKE_C_STANDARD 99)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(BuildGame src/main.cpp src/Core/Utils/Debug.cpp src/Core/Utils/Debug.hpp src/Core/InputManager.cpp src/Core/InputManager.h src/Core/GameObject.cpp src/Core/GameObject.h src/BouncingBall.cpp src/BouncingBall.h)
target_link_libraries(BuildGame PUBLIC raylib)