#pragma once

class LinearCongruentialGenerator {
	long long modulus;
	int multiplier;
	int increment;
	int seed {0};
	int state;

	void updateState(); // computes the next state; called by randint and randfloat

public:
	LinearCongruentialGenerator(long long modulus, int multiplier, int increment);
	int getSeed() { return seed; };
	long long getModulus() { return modulus; };

	int rand();
	float randfloat(); // return a number between 0 and 1
};
