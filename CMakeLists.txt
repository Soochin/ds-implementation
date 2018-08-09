cmake_minimum_required(VERSION 3.9)
project(ds_implementation)

set(CMAKE_CXX_STANDARD 11)
set(GTEST_DIR "lib/googletest-master")
add_subdirectory(${GTEST_DIR} build)
include_directories(${GTEST_DIR}/include ${GTEST_DIR})
include_directories(src test)
file(GLOB SOURCES src/*.cpp)
file(GLOB TESTS test/*.cpp)


add_executable(ds_implementation
        ${SOURCES} ${TESTS})


target_link_libraries(ds_implementation gtest gtest_main)

