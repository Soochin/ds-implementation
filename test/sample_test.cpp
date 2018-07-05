//
// Created by trevor on 6/21/18.
//
#include <MinHeap.hpp>
#include <gtest/gtest.h>

TEST(sampleTestCaseName, sampleTestname)
{
    EXPECT_EQ(1,1);
}


TEST(MinHeapTest, correctEmptySize)
{
    MinHeap<int> h = MinHeap<int>();
    ASSERT_EQ(h.isEmpty(), true);
    ASSERT_EQ(h.size(), 0);

}

TEST(MinHeapTest, addOne)
{
    MinHeap<int> h = MinHeap<int>();
    h.add(1);
    ASSERT_EQ(h.isEmpty(), false);
    ASSERT_EQ(h.size(),1);
    ASSERT_EQ(h.contains(1), true);
    h.print();
}

TEST(MinHeapTest, addTwo)
{
    MinHeap<int> h = MinHeap<int>();
    h.add(1);
    h.add(0);
    ASSERT_EQ(h.size(), 2);
    ASSERT_EQ(h.contains(0), true);
    h.print();
}