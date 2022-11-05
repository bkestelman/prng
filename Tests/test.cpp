#include "pch.h"
#include "../linear_congruential.h"
#include <limits.h>
TEST(TestLinearCongruentialGenerator, TestDefaultSeed) {
	LinearCongruentialGenerator lcg { 9, 4, 1 };
	EXPECT_EQ(lcg.getSeed(), 0);
}

TEST(TestLinearCongruentialGenerator, TestCycle) {
	LinearCongruentialGenerator lcg{ 9, 4, 1 };
	EXPECT_EQ(lcg.randint(), 1);
	EXPECT_EQ(lcg.randint(), 5);
	EXPECT_EQ(lcg.randint(), 3);
	EXPECT_EQ(lcg.randint(), 4);
	EXPECT_EQ(lcg.randint(), 8);
	EXPECT_EQ(lcg.randint(), 6);
	EXPECT_EQ(lcg.randint(), 7);
	EXPECT_EQ(lcg.randint(), 2);
	EXPECT_EQ(lcg.randint(), 0);
}

TEST(TestLinearCongruentialGenerator, TestFloatRange) {
	int modulus = 9;
	LinearCongruentialGenerator lcg{ modulus, 4, 1 };
	for (int i = 0; i < modulus; i++) {
		float rand = lcg.randfloat();
		EXPECT_TRUE(rand <= 1);
		EXPECT_TRUE(rand >= 0);
	}
}

TEST(TestLinearCongruentialGenerator, TestLargeModulus) {
	long long modulus = LLONG_MAX;
	LinearCongruentialGenerator lcg{ modulus, 4, 1 };
	EXPECT_EQ(modulus, lcg.getModulus());
}
