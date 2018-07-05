cmake_minimum_required(VERSION 3.9)
project(ds_implementation)

set(CMAKE_CXX_STANDARD 11)
set(GTEST_DIR "lib/googletest-master")
add_subdirectory(${GTEST_DIR} build)
include_directories(${GTEST_DIR}/include ${GTEST_DIR})
include_directories(src test)
set(CMAKE_VERBOSE_MAKEFILE ON)



add_executable(ds_implementation
        src/MinHeap.hpp
        src/MinHeapException.hpp
        src/MinPriorityQueue.hpp
        test/main.cpp
        test/sample_test.cpp)


target_link_libraries(ds_implementation gtest gtest_main)

