#include <gtest/gtest.h>
#include "MinHeap.hpp"

TEST(MinHeap_Test, sizeIsZeroWhenDefaultConstructed)
{
	MinHeap<int> mh;

	EXPECT_EQ(0, mh.size());
	EXPECT_TRUE(mh.isEmpty());
}

TEST(MinHeap_Test, heightIsNegativeOneWhenDefaultConstructed)
{
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

TEST(MinHeap_Test, buildHeap)
{
	//source: https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/DemoHeapify.pdf
	std::vector<int> sample = {8,12,9,7,22,3,26,14,11,15,22};
	MinHeap<int> h = MinHeap<int>(sample);
	h.print();
}


TEST(MinHeap_Test, extractMin)
{
    //source: http://www.algolist.net/Data_structures/Binary_heap/Remove_minimum

    std::vector<int> sample = {1,3,6,5,9,8};
    MinHeap<int> h = MinHeap<int>(sample);
    h.print();
	ASSERT_EQ(h.getMin(), 1);
	h.removeMin();
	h.print();
	ASSERT_EQ(h.size(), 5);
	ASSERT_EQ(h.getMin(), 3);
}

TEST(MinHeap_Test, MinHeapCanBeCopyConstructed_WithSeparateContents)
{
}

TEST(MinHeap_Test, MinHeapCanBeMoveConstructed_LeavingOriginalEmpty)
{
}

TEST(MinHeap_Test, MinHeapCanBeCopyAssigned_WithSeparateContents)
{
}

TEST(MinHeap_Test, MinHeapCanBeMoveAssigned_SwappingContents)
{
}