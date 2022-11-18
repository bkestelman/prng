#pragma once
#include "linear_congruential.h"
#include <cstdint>

template<typename T = int64_t> class MixedCongruentialGenerator : public LinearCongruentialGenerator<T> {
	int64_t multiplier;
	int64_t increment;

	void updateState() override {
		state = (multiplier * state + increment) % modulus;
	};

public:
	MixedCongruentialGenerator(T modulus, T multiplier, T increment) :
		LinearCongruentialGenerator(modulus, 0), multiplier(multiplier), increment(increment) {};
};
