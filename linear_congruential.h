#pragma once

class LinearCongruentialGenerator {
protected:
	long long modulus;
	long long state;

	virtual void updateState() = 0;

public:
	LinearCongruentialGenerator(long long modulus, long long state) : modulus(modulus), state(state) {};
	void seed(long long seed) { state = seed; };
	long long getModulus() { return modulus; };

	virtual long long rand() { updateState(); return state; }; // return a positive integer less than modulus
	float randfloat() { return (float)rand() / modulus; }; // return a number between 0 and 1
};
