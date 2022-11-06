#include "linear_congruential.h"
#include "multiplicative_congruential.h"
#include <cstdint>

MultiplicativeCongruentialGenerator::MultiplicativeCongruentialGenerator(int64_t modulus, int64_t multiplier) :
	LinearCongruentialGenerator(modulus, 1), multiplier(multiplier) {};

void MultiplicativeCongruentialGenerator::updateState() {
	state = (multiplier * state) % modulus;
}
