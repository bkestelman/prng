#include "gtest/gtest.h"
#include "pch.h"
#include "../include/LFSR.h"

TEST(TestLFSR, TestBitValAtIndex) {
	int seed = 9; // 1001
	LFSR lfsr{ 4, seed, 0, 1 };
	EXPECT_EQ(lfsr.bitVal(0), 1);
	EXPECT_EQ(lfsr.bitVal(1), 0);
	EXPECT_EQ(lfsr.bitVal(2), 0);
	EXPECT_EQ(lfsr.bitVal(3), 1);
}
TEST(TestLFSR, Test4BitLFSR) {
	/* Test the example from computerphile: https://www.youtube.com/watch?v=Ks1pw1X22y4 */
	int seed = 9; // 1001
	LFSR lfsr{ 4, seed, 0, 1 };
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 1);
}
