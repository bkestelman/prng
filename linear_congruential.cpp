#include "linear_congruential.h"

LinearCongruentialGenerator::LinearCongruentialGenerator(int modulus, int multiplier, int increment) :
	modulus(modulus), multiplier(multiplier), increment(increment) {
	state = seed;
};

int LinearCongruentialGenerator::random() {
	state = (multiplier * state + increment) % modulus;
	return state;
}
