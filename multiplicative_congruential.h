#pragma once
#include "linear_congruential.h"
#include <cstdint>

template<typename T = int64_t> class MultiplicativeCongruentialGenerator : public LinearCongruentialGenerator<T> {
	int64_t multiplier;

	void updateState() override {
		state = (multiplier * state) % modulus;
	};

public:
	MultiplicativeCongruentialGenerator(T modulus, T multiplier) :
		LinearCongruentialGenerator(modulus, 1), multiplier(multiplier) {};
};
