# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(SingleFileProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable (replace main.cpp with your file name if different)
add_executable(single_file main.cpp)
