cmake_minimum_required(VERSION 3.0.0)
project(RedBlackTree VERSION 0.1.0)

add_executable(RedBlackTree main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
