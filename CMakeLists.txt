cmake_minimum_required(VERSION 3.12)
project(OPZ1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(OPZ1 main.cpp OPZ.h OPZ.cpp)
add_executable(test.cpp OPZ.h OPZ.cpp)

target_link_libraries(OPZ1 gtest gtest_main)