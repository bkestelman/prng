#include "common_generators.h"

MultiplicativeCongruentialGenerator mersenneMinimalStandard() {
	int64_t mersennePrime = ((int64_t)1 << 31) - 1; // 2^31 - 1
	int64_t multiplier = 16807; // 7^5 (the "minimal standard")
	return MultiplicativeCongruentialGenerator{ mersennePrime, multiplier };
}
