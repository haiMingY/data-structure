cmake_minimum_required(VERSION 3.0.0)
project(hashTable VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(hashTable main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
