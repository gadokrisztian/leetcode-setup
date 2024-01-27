cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS true) # for clangd lsp

add_executable(leetcode main.cpp)

add_subdirectory(3rdparty/fmt)

target_link_libraries(leetcode PRIVATE fmt::fmt)
