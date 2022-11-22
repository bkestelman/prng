#include "gtest/gtest.h"
#include "pch.h"
#include "../include/LFSR.h"

TEST(TestLFSR, TestBitVal) {
	int seed = 44; // 101100
	LFSR lfsr{ 4, seed, 0, 1 };
	EXPECT_EQ(lfsr.bitVal(0), 0);
	EXPECT_EQ(lfsr.bitVal(1), 0);
	EXPECT_EQ(lfsr.bitVal(2), 1);
	EXPECT_EQ(lfsr.bitVal(3), 1);
	EXPECT_EQ(lfsr.bitVal(4), 0);
	EXPECT_EQ(lfsr.bitVal(5), 1);
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

TEST(TestLFSR, TestTapsFromPrimitiveTrinomial) {
	int seed = 9; // 1001
	LFSR lfsr{ 4, seed };
	EXPECT_EQ(lfsr.getTap1IndexFromRight(), 3);
	EXPECT_EQ(lfsr.getTap2IndexFromRight(), 0);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 0);
	EXPECT_EQ(lfsr.rand(), 1);
	EXPECT_EQ(lfsr.rand(), 1);
}
