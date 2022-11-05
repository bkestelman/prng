#include "pch.h"
#include "../linear_congruential.h"
TEST(TestLinearCongruentialGenerator, TestDefaultSeed) {
	LinearCongruentialGenerator lcg { 9, 4, 1 };
	EXPECT_EQ(lcg.getSeed(), 0);
}

TEST(TestLinearCongruentialGenerator, TestCycle) {
	LinearCongruentialGenerator lcg{ 9, 4, 1 };
	EXPECT_EQ(lcg.random(), 1);
	EXPECT_EQ(lcg.random(), 5);
	EXPECT_EQ(lcg.random(), 3);
	EXPECT_EQ(lcg.random(), 4);
	EXPECT_EQ(lcg.random(), 8);
	EXPECT_EQ(lcg.random(), 6);
	EXPECT_EQ(lcg.random(), 7);
	EXPECT_EQ(lcg.random(), 2);
	EXPECT_EQ(lcg.random(), 0);
}
