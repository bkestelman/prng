#include "pch.h"
#include "../include/stats.h"
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
	vector<float> vec3{ 4, 7, 7 };
	EXPECT_NEAR(correlation(vec1, vec1), 1, 0.0001);
	EXPECT_NEAR(correlation(vec1, vec3), 0.866, 0.0001);
}

TEST(TestStats, TestCorrelationSymmetry) {
	vector<float> vec1{ 1, 3, 5 };
	vector<float> vec2{ 2, 6, 10 };
	EXPECT_NEAR(correlation(vec1, vec2), correlation(vec2, vec1), 0.0001);
}

TEST(TestStats, TestCorrelationScaleInvariance) {
	vector<float> vec1{ 1, 3, 5 };
	vector<float> vec2{ 4, 7, 7 };
	vector<float> vec1_scaled{ 2, 6, 10 };
	EXPECT_NEAR(correlation(vec1, vec2), correlation(vec1_scaled, vec2), 0.0001);
	vector<float> vec1_shifted{ 3, 5, 7 };
	EXPECT_NEAR(correlation(vec1, vec2), correlation(vec1_shifted, vec2), 0.0001);
}

TEST(TestStats, TestAutocorrelation) {
	int lag = 1;
	vector<float> vec{ 1, 3, 5, 7 };
	EXPECT_NEAR(autocorrelation(vec, lag), 0.25, 0.0001);
}
