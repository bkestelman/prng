#pragma once

class LinearCongruentialGenerator {
	int modulus;
	int multiplier;
	int increment;
	int seed {0};
	int state;

	void updateState(); // computes the next state; called by randint and randfloat

public:
	LinearCongruentialGenerator(int modulus, int multiplier, int increment);
	int getSeed() { return seed; };

	int randint();
	float randfloat(); // return a number between 0 and 1
};
