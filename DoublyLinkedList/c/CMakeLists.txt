cmake_minimum_required(VERSION 3.0.0)
project(doubleList VERSION 0.1.0 )

include(CTest)
enable_testing()

add_library(list_lib list_node.h list_node.c doubly_linked_list.h doubly_linked_list.c)

add_executable(doubleList main.c)

target_link_libraries(doubleList list_lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
