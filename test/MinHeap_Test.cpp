#include <gtest/gtest.h>
#include "MinHeap.hpp"

TEST(MinHeap_Test, sizeIsZeroWhenDefaultConstructed)
{
	MinHeap<int> mh;

	EXPECT_EQ(0, mh.size());
	EXPECT_TRUE(mh.isEmpty());
}

TEST(MinHeap_Test, nameATest)
{
}