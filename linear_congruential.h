#pragma once

class LinearCongruentialGenerator {
	long long modulus;
	int multiplier;
	int increment;
	long long state {0}; // default seed is 0

	void updateState(); // computes the next state; called by randint and randfloat

public:
	LinearCongruentialGenerator(long long modulus, int multiplier, int increment);
	void seed(long long seed) { state = seed; };
	long long getModulus() { return modulus; };

	long long rand();
	float randfloat(); // return a number between 0 and 1
};
