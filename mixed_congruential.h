#pragma once
#include "linear_congruential.h"

class MixedCongruentialGenerator : public LinearCongruentialGenerator {
	long long multiplier;
	long long increment;

	void updateState() override;

public:
	MixedCongruentialGenerator(long long modulus, long long multiplier, long long increment);
};
