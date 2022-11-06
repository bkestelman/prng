#include "linear_congruential.h"
#include "mixed_congruential.h"
#include <cstdint>

MixedCongruentialGenerator::MixedCongruentialGenerator(int64_t modulus, int64_t multiplier, int64_t increment) :
	LinearCongruentialGenerator(modulus, 0), multiplier(multiplier), increment(increment) {};

void MixedCongruentialGenerator::updateState() {
	state = (multiplier * state + increment) % modulus;
}
