cmake_minimum_required(VERSION 3.10)
project(BalancedLists)

set(CMAKE_CXX_STANDARD 17)

# Main executable
add_executable(main main.cpp fisher_yates.cpp)

# Unit tests executable
add_executable(unittests unittests.cpp fisher_yates.cpp)
