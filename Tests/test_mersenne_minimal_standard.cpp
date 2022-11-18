#include "gtest/gtest.h"
#include "pch.h"
#include "../include/common_generators.h"
#include "../include/multiplicative_congruential.h"
#include<cmath>

TEST(TestMersenneMinimalStandard, TestMersenneModulus) {
	MultiplicativeCongruentialGenerator<> mcg = mersenneMinimalStandard();
	EXPECT_EQ(mcg.getModulus(), pow(2, 31) - 1);
}
