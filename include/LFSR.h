#pragma once

/*
* Linear Feedback Shift Register PRNG
*/
class LFSR {
	int size;
	int bits;
	int tap1IndexFromRight, tap2IndexFromRight;

	static int PRIMITIVE_TRINOMIALS[5][2];

	void updateState() {
		int newBit = (bitVal(tap1IndexFromRight) ^ bitVal(tap2IndexFromRight)) << (size - 1);
		bits = bits >> 1;
		bits = newBit | bits;
	}

	void setTaps() {
		tap1IndexFromRight = PRIMITIVE_TRINOMIALS[size - 2][0] - 1;
		tap2IndexFromRight = PRIMITIVE_TRINOMIALS[size - 2][1] - 1;
	}
public:
	/* LFSR with taps specified */
	LFSR(int size, int seed, int tap1FromRight, int tap2FromRight) : size(size), bits(seed), 
		tap1IndexFromRight(tap1FromRight), tap2IndexFromRight(tap2FromRight) {};
	/* LFSR for given number of bits n, with taps chosen according to a primitive trinomial of degree n */
	LFSR(int size, int seed) : size(size), bits(seed) { setTaps(); };
	int rand() { updateState(); return bits & 1; };

	int bitVal(int indexFromRight) {
		return (bits >> indexFromRight) & 1;
	}

	int getTap1IndexFromRight() { return tap1IndexFromRight; };
	int getTap2IndexFromRight() { return tap2IndexFromRight; };
};

int LFSR::PRIMITIVE_TRINOMIALS[5][2] = {
		{2, 1}, // x^2 + x + 1
		{3, 1}, // x^3 + x + 1
		{4, 1}, // x^4 + x + 1
		{5, 2}, // x^5 + x^2 + 1
		{6, 1}
};
