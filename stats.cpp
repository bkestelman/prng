#include "stats.h"

using std::vector;

float mean(vector<float> nums) {
	float ans = 0;
	for (float num : nums) {
		ans += num;
	}
	return ans / nums.size();
}

float variance(vector<float> nums) {
	float ans = 0;
	float avg = mean(nums);
	for (float num : nums) {
		ans += (num - avg) * (num - avg);
	}
	return ans / nums.size();
}

float std_dev(vector<float> nums) {
	return sqrt(variance(nums));
}

float correlation(vector<float> vec1, vector<float> vec2) {
	float ans = 0;
	float avg1 = mean(vec1);
	float avg2 = mean(vec2);
	float std1 = std_dev(vec1);
	float std2 = std_dev(vec2);
	for (int i = 0; i < vec1.size(); i++) {
		ans += (vec1[i] - avg1) / std1 * (vec2[i] - avg2) / std2;
	}
	return ans / vec1.size();
}

float autocorrelation(vector<float> vec, int lag) {
	//TODO: just return correlation(vec[:N-k], vec[k:]) (nvm, looks like it's not quite the same)
	float ans = 0;
	float avg = mean(vec);
	float std = std_dev(vec);
	for (int i = 0; i < vec.size() - lag; i++) {
		ans += (vec[i] - avg) * (vec[i + lag] - avg) / (std * std);
	}
	return ans / vec.size();
}
