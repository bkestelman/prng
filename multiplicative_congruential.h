#pragma once
#include "linear_congruential.h"
#include <cstdint>

class MultiplicativeCongruentialGenerator : public LinearCongruentialGenerator {
	int64_t multiplier;

	void updateState() override;

public:
	MultiplicativeCongruentialGenerator(int64_t modulus, int64_t multiplier);
};
