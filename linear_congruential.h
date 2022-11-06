#pragma once
#include <cstdint>

class LinearCongruentialGenerator {
protected:
	int64_t modulus;
	int64_t state;

	virtual void updateState() = 0;

public:
	LinearCongruentialGenerator(int64_t modulus, int64_t state) : modulus(modulus), state(state) {};
	void seed(int64_t seed) { state = seed; };
	int64_t getModulus() { return modulus; };

	virtual int64_t rand() { updateState(); return state; }; // return a positive integer less than modulus
	float randfloat() { return (float)rand() / modulus; }; // return a number between 0 and 1
};
