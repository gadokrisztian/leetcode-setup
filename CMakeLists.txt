cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(leetcode main.cpp)

add_subdirectory(3rdparty/fmt)

target_link_libraries(leetcode PRIVATE fmt::fmt)