#include "common_generators.h"

MultiplicativeCongruentialGenerator<int64_t> mersenneMinimalStandard() {
	int64_t mersennePrime = ((int64_t)1 << 31) - 1; // 2^31 - 1
	int64_t multiplier = 16807; // 7^5 (the "minimal standard")
	return MultiplicativeCongruentialGenerator<int64_t>{ mersennePrime, multiplier };
}

MultiplicativeCongruentialGenerator<int64_t> RANDU() {
	int64_t modulus = ((int64_t)1 << 31) - 1; // 2^31 - 1
	int64_t multiplier = 65539;
	return MultiplicativeCongruentialGenerator<int64_t>{ modulus, multiplier };
}
