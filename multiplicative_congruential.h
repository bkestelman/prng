#pragma once
#include "linear_congruential.h"

class MultiplicativeCongruentialGenerator : public LinearCongruentialGenerator {
	int multiplier;

	void updateState() override;

public:
	MultiplicativeCongruentialGenerator(long long modulus, int multiplier);
};
