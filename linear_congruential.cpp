#include "linear_congruential.h"

LinearCongruentialGenerator::LinearCongruentialGenerator(long long modulus, int multiplier, int increment) :
	modulus(modulus), multiplier(multiplier), increment(increment) {};

void LinearCongruentialGenerator::updateState() {
	state = (multiplier * state + increment) % modulus;
}

int LinearCongruentialGenerator::rand() {
	updateState();
	return state;
}

float LinearCongruentialGenerator::randfloat() {
	updateState();
	return (float)state / modulus;
}
