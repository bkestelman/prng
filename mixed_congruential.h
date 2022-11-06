#pragma once
#include "linear_congruential.h"

class MixedCongruentialGenerator : public LinearCongruentialGenerator {
	int multiplier;
	int increment;

	void updateState() override;

public:
	MixedCongruentialGenerator(long long modulus, int multiplier, int increment);
};
