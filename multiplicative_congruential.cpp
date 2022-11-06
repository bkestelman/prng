#include "linear_congruential.h"
#include "multiplicative_congruential.h"

MultiplicativeCongruentialGenerator::MultiplicativeCongruentialGenerator(long long modulus, long long multiplier) :
	LinearCongruentialGenerator(modulus, 1), multiplier(multiplier) {};

void MultiplicativeCongruentialGenerator::updateState() {
	state = (multiplier * state) % modulus;
}
