#pragma once
#include "linear_congruential.h"
#include <cstdint>

class MixedCongruentialGenerator : public LinearCongruentialGenerator {
	int64_t multiplier;
	int64_t increment;

	void updateState() override;

public:
	MixedCongruentialGenerator(int64_t modulus, int64_t multiplier, int64_t increment);
};
