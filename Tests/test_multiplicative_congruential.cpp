#include "pch.h"
#include "../multiplicative_congruential.h"
#include <limits.h>
TEST(TestMultiplicativeCongruentialGenerator, TestDefaultSeed) {
	MultiplicativeCongruentialGenerator mcg{ 9, 1 };
	EXPECT_EQ(mcg.rand(), 1); // with multiplier 1, rand should return the seed
}

TEST(TestMultiplicativeCongruentialGenerator, TestSetSeed) {
	MultiplicativeCongruentialGenerator mcg{ 9, 1 };
	mcg.seed(5);
	EXPECT_EQ(mcg.rand(), 5); // with multiplier 1, rand should return the seed
}

TEST(TestMultiplicativeCongruentialGenerator, TestCycle) {
	MultiplicativeCongruentialGenerator mcg{ 5, 2 };
	EXPECT_EQ(mcg.rand(), 2);
	EXPECT_EQ(mcg.rand(), 4);
	EXPECT_EQ(mcg.rand(), 3);
	EXPECT_EQ(mcg.rand(), 1);
}

TEST(TestMultiplicativeCongruentialGenerator, TestFloatRange) {
	int modulus = 5, multiplier = 2;
	MultiplicativeCongruentialGenerator mcg{ modulus, multiplier };
	for (int i = 0; i < modulus; i++) {
		float rand = mcg.randfloat();
		EXPECT_TRUE(rand <= 1);
		EXPECT_TRUE(rand >= 0);
	}
}

TEST(TestMultiplicativeCongruentialGenerator, TestLargeModulus) {
	long long modulus = LLONG_MAX;
	MultiplicativeCongruentialGenerator mcg{ modulus, 1 }; /* 1 and 0 chosen so the result of rand will also be very large */
	long long seed = modulus - 1;
	mcg.seed(seed);
	EXPECT_EQ(modulus, mcg.getModulus());
	EXPECT_EQ(mcg.rand(), seed); /* Test that rand does not overflow with large modulus */
}
