#pragma once

class LinearCongruentialGenerator {
	long long modulus;
	int multiplier;
	int increment;
	int state {0}; // default seed is 0

	void updateState(); // computes the next state; called by randint and randfloat

public:
	LinearCongruentialGenerator(long long modulus, int multiplier, int increment);
	void seed(int seed) { state = seed; };
	long long getModulus() { return modulus; };

	int rand();
	float randfloat(); // return a number between 0 and 1
};
