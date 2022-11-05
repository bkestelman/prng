#include "pch.h"
#include "../linear_congruential.h"
#include <limits.h>
TEST(TestLinearCongruentialGenerator, TestDefaultSeed) {
	LinearCongruentialGenerator lcg { 9, 1, 0 };
	EXPECT_EQ(lcg.rand(), 0); // with 0 increment, rand should return the seed
}

TEST(TestLinearCongruentialGenerator, TestSetSeed) {
	LinearCongruentialGenerator lcg{ 9, 1, 0 };
	lcg.seed(5);
	EXPECT_EQ(lcg.rand(), 5); // with 0 increment, rand should return the seed
}

TEST(TestLinearCongruentialGenerator, TestCycle) {
	LinearCongruentialGenerator lcg{ 9, 4, 1 };
	EXPECT_EQ(lcg.rand(), 1);
	EXPECT_EQ(lcg.rand(), 5);
	EXPECT_EQ(lcg.rand(), 3);
	EXPECT_EQ(lcg.rand(), 4);
	EXPECT_EQ(lcg.rand(), 8);
	EXPECT_EQ(lcg.rand(), 6);
	EXPECT_EQ(lcg.rand(), 7);
	EXPECT_EQ(lcg.rand(), 2);
	EXPECT_EQ(lcg.rand(), 0);
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
	LinearCongruentialGenerator lcg{ modulus, 1, 0 }; /* 1 and 0 chosen so the result of rand will also be very large */
	long long seed = modulus - 1;
	lcg.seed(seed);
	EXPECT_EQ(modulus, lcg.getModulus());
	EXPECT_EQ(lcg.rand(), seed); /* Test that rand does not overflow with large modulus */
}
