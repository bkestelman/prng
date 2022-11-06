#pragma once

class MultiplicativeCongruentialGenerator {
	long long modulus;
	int multiplier;
	long long state{ 1 }; // default seed is 1

	void updateState(); // computes the next state; called by randint and randfloat

public:
	MultiplicativeCongruentialGenerator(long long modulus, int multiplier);
	void seed(long long seed) { state = seed; };
	long long getModulus() { return modulus; };

	long long rand();
	float randfloat(); // return a number between 0 and 1
};
