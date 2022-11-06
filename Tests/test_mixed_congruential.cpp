#include "pch.h"
#include "../mixed_congruential.h"
#include <limits.h>
TEST(TestMixedCongruentialGenerator, TestDefaultSeed) {
	MixedCongruentialGenerator mxcg { 9, 1, 0 };
	EXPECT_EQ(mxcg.rand(), 0); // with increment 0 and multiplier 1, rand should return the seed
}

TEST(TestMixedCongruentialGenerator, TestSetSeed) {
	MixedCongruentialGenerator mxcg{ 9, 1, 0 };
	mxcg.seed(5);
	EXPECT_EQ(mxcg.rand(), 5); // with increment 0 and multiplier 1, rand should return the seed
}

TEST(TestMixedCongruentialGenerator, TestCycle) {
	MixedCongruentialGenerator mxcg{ 9, 4, 1 };
	EXPECT_EQ(mxcg.rand(), 1);
	EXPECT_EQ(mxcg.rand(), 5);
	EXPECT_EQ(mxcg.rand(), 3);
	EXPECT_EQ(mxcg.rand(), 4);
	EXPECT_EQ(mxcg.rand(), 8);
	EXPECT_EQ(mxcg.rand(), 6);
	EXPECT_EQ(mxcg.rand(), 7);
	EXPECT_EQ(mxcg.rand(), 2);
	EXPECT_EQ(mxcg.rand(), 0);
}

TEST(TestMixedCongruentialGenerator, TestFloatRange) {
	int modulus = 9;
	MixedCongruentialGenerator mxcg{ modulus, 4, 1 };
	for (int i = 0; i < modulus; i++) {
		float rand = mxcg.randfloat();
		EXPECT_TRUE(rand <= 1);
		EXPECT_TRUE(rand >= 0);
	}
}

TEST(TestMixedCongruentialGenerator, TestLargeModulus) {
	int64_t modulus = LLONG_MAX, multiplier = 1;
	MixedCongruentialGenerator mxcg{ modulus, multiplier, 0 }; /* 1 and 0 chosen so the result of rand will also be very large */
	int64_t seed = modulus - 1;
	mxcg.seed(seed);
	EXPECT_EQ(modulus, mxcg.getModulus());
	EXPECT_EQ(mxcg.rand(), seed); /* Test that rand does not overflow with large modulus */
	multiplier = modulus; /* Test overflow with large multiplier */
	MixedCongruentialGenerator mxcg2{ modulus, multiplier, 0 };
	EXPECT_EQ(mxcg2.rand(), 0); /* Because multiplier = modulus, seed * multiplier = seed * modulus = 0 mod modulus */
}
