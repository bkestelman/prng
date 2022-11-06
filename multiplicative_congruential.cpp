#include "multiplicative_congruential.h"

MultiplicativeCongruentialGenerator::MultiplicativeCongruentialGenerator(long long modulus, int multiplier) :
	modulus(modulus), multiplier(multiplier) {};

void MultiplicativeCongruentialGenerator::updateState() {
	state = (multiplier * state) % modulus;
}

long long MultiplicativeCongruentialGenerator::rand() {
	updateState();
	return state;
}

float MultiplicativeCongruentialGenerator::randfloat() {
	updateState();
	return (float)state / modulus;
}
