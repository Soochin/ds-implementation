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
	MinHeap<int> mh1;
	for (int i = 1; i <= 10; ++i) {
		mh1.add(i);
	}

	MinHeap<int> mh2 = mh1; // copy construct

	EXPECT_EQ(10, mh1.size());
	EXPECT_EQ(10, mh2.size());

	for (int i = 1; i <= 10; ++i) {
		EXPECT_TRUE(mh2.contains(i));
	}

	for (int i = 11; i <= 20; ++i) {
		EXPECT_FALSE(mh2.contains(i));
	}
}

TEST(MinHeap_Test, MinHeapCanBeMoveConstructed_LeavingOriginalEmpty)
{
	MinHeap<int> mh1;
	for (int i = 1; i <= 7; ++i) {
		mh1.add(i);
	}

	MinHeap<int> mh2 = std::move(mh1);

	EXPECT_EQ(0, mh1.size());

	EXPECT_EQ(7, mh2.size());

	for (int i = 1; i <= 7; ++i) {
        EXPECT_TRUE(mh2.contains(i));
    }

    for (int i = 9; i <= 20; ++i) {
        EXPECT_FALSE(mh2.contains(i));
    }
}

TEST(MinHeap_Test, MinHeapCanBeCopyAssigned_WithSeparateContents)
{
	MinHeap<int> mh1;
    for (int i = 9; i <= 20; i+=2) {
        mh1.add(i);
    }

    MinHeap<int> mh2;
    for (int i = 1; i <= 8; ++i) {
        mh2.add(i);
    }

    mh1 = mh2;

    EXPECT_EQ(8, mh1.size());

    EXPECT_EQ(8, mh2.size());

    mh2.add(100);
    
    EXPECT_TRUE(mh2.contains(100));
    EXPECT_FALSE(mh1.contains(100));


    for (int i = 1; i <= 8; ++i) {
        EXPECT_TRUE(mh1.contains(i));
        EXPECT_TRUE(mh2.contains(i));
    }

    for (int i = 9; i <= 20; i+=2) {
        EXPECT_FALSE(mh1.contains(i));
        EXPECT_FALSE(mh2.contains(i));
    }
}

TEST(MinHeap_Test, MinHeapCanBeMoveAssigned_SwappingContents)
{
	MinHeap<int> mh1;
    for (int i = 9; i <= 30; i+=2) {
        mh1.add(i);
    }

    MinHeap<int> mh2;
    for (int i = 1; i <= 7; ++i) {
        mh2.add(i);
    }

    mh1 = std::move(mh2);

    EXPECT_EQ(7, mh1.size());

    EXPECT_EQ(11, mh2.size());

    for (int i = 1; i <= 7; ++i) {
        EXPECT_TRUE(mh1.contains(i));
        EXPECT_FALSE(mh2.contains(i));
    }

    for (int i = 9; i <= 30; i+=2) {
        EXPECT_FALSE(mh1.contains(i));
        EXPECT_TRUE(mh2.contains(i));
    }
}