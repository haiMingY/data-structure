cmake_minimum_required(VERSION 3.0.0)
project(LinkList VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(list_lib STATIC LinkListNode.h LinkListNode.c LinkList.h LinkList.c)

add_executable(LinkList main.c)


target_link_libraries(LinkList list_lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
