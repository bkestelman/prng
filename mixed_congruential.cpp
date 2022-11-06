#include "linear_congruential.h"
#include "mixed_congruential.h"

MixedCongruentialGenerator::MixedCongruentialGenerator(long long modulus, long long multiplier, long long increment) :
	LinearCongruentialGenerator(modulus, 0), multiplier(multiplier), increment(increment) {};

void MixedCongruentialGenerator::updateState() {
	state = (multiplier * state + increment) % modulus;
}
