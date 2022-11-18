#pragma once
#include <cstdint>

template<typename T> class LinearCongruentialGenerator {
protected:
	T modulus;
	T state;

	virtual void updateState() = 0;

public:
	LinearCongruentialGenerator(T modulus, T state) : modulus(modulus), state(state) {};
	void seed(T seed) { state = seed; };
	T getModulus() { return modulus; };

	virtual T rand() { updateState(); return state; }; // return a positive integer less than modulus
	float randfloat() { return (float)rand() / modulus; }; // return a number between 0 and 1
};
