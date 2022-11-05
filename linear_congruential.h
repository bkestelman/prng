#pragma once

class LinearCongruentialGenerator {
	int modulus;
	int multiplier;
	int increment;
	int seed {0};
	int state;

public:
	LinearCongruentialGenerator(int modulus, int multiplier, int increment);
	int getSeed() { return seed; };

	int random();
};
