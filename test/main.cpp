//
// Created by trevor on 6/21/18.
//
#include <iostream>
#include <gtest/gtest.h>
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    std::cout << "Running Google Test" << std::endl;
    return RUN_ALL_TESTS();
}
