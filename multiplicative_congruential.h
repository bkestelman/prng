#pragma once
#include "linear_congruential.h"

class MultiplicativeCongruentialGenerator : public LinearCongruentialGenerator {
	long long multiplier;

	void updateState() override;

public:
	MultiplicativeCongruentialGenerator(long long modulus, long long multiplier);
};
