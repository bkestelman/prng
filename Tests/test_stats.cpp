#include "pch.h"
#include "../stats.h"
#include <vector>

using std::vector;

TEST(TestStats, TestMean) {
	vector<float> nums{ 1, 3, 5 };
	EXPECT_EQ(mean(nums), 3);
}

TEST(TestStats, TestVariance) {
	vector<float> nums{ 1, 5 };
	EXPECT_EQ(variance(nums), 4);
}

TEST(TestStats, TestStandardDeviation) {
	vector<float> nums{ 1, 5 };
	EXPECT_EQ(std_dev(nums), 2);
}

TEST(TestStats, TestCorrelation) {
	vector<float> vec1{ 1, 3, 5 };
	vector<float> vec2{ 2, 6, 10 };
	EXPECT_EQ(correlation(vec1, vec1), 1);
}
