# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(auto_scoreboard)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target
add_executable(auto_scoreboard main.cpp)
