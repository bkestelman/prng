#include "gtest/gtest.h"
#include "pch.h"
#include "../multiplicative_congruential.h"
#include "../stats.h"

TEST(TestPRNGStats, TestMultiplicativeAutocorrelation) {
	/* Example from Gentle 1998 
	* The large lag 1 autocorrelation results from the small multiplier 
	* (or from one close to the modulus)
	*/
	int64_t modulus = 31, multiplier = 3, seed = 9;
	MultiplicativeCongruentialGenerator<> mcg{ modulus, multiplier };
	mcg.seed(seed);
	vector<float> samples;
	for (int i = 0; i < modulus - 1; i++) {
		samples.push_back(mcg.rand());
	}
	EXPECT_EQ(samples.front(), 27);
	EXPECT_EQ(samples.back(), 9);
	EXPECT_NEAR(mean(samples) / 30, 0.517, 0.001);
	EXPECT_NEAR(autocorrelation(samples, 1), 0.27, 0.01);
	EXPECT_NEAR(autocorrelation(samples, 2), 0.16, 0.01);
	EXPECT_NEAR(autocorrelation(samples, 3), -0.10, 0.01);
	EXPECT_NEAR(autocorrelation(samples, 4), 0.06, 0.01);
	EXPECT_NEAR(autocorrelation(samples, 5), 0.07, 0.01);
}
