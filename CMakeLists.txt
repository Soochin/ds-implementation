cmake_minimum_required(VERSION 3.9)
project(ds_implementation)

set(CMAKE_CXX_STANDARD 11)
set(GTEST_DIR "/home/trevor/googletest-master")


include_directories(GTEST_DIR/googletest/include)
include_directories(GTEST_DIR/googlemock/include)



add_executable(ds_implementation
        src/MinHeap.hpp
        src/MinHeapException.hpp
        src/MinPriorityQueue.hpp test/main.cpp)


target_link_libraries(ds_implementation gtest gtest_main)

target_link_libraries(ds_implementation gmock gmock_main)