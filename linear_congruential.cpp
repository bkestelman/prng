#include "linear_congruential.h"

LinearCongruentialGenerator::LinearCongruentialGenerator(int modulus, int multiplier, int increment) :
	modulus(modulus), multiplier(multiplier), increment(increment) {
	state = seed;
};

void LinearCongruentialGenerator::updateState() {
	state = (multiplier * state + increment) % modulus;
}

int LinearCongruentialGenerator::randint() {
	updateState();
	return state;
}

float LinearCongruentialGenerator::randfloat() {
	updateState();
	return (float)state / modulus;
}
