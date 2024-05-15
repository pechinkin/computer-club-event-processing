cmake_minimum_required(VERSION 3.0)
project(yadro_test)

set(CMAKE_CXX_STANDARD 20)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(test main.cpp src/time.cpp src/club.cpp src/event.cpp)
