#pragma once

/*
* Linear Feedback Shift Register PRNG
*/
class LFSR {
	int size;
	int bits;
	int tap1Index, tap2Index;

	void updateState() {
		int newBit = (bitVal(tap1Index) ^ bitVal(tap2Index)) << (size - 1);
		bits = bits >> 1;
		bits = newBit | bits;
	}
public:
	LFSR(int size, int seed, int tap1, int tap2) : size(size), bits(seed), tap1Index(tap1), tap2Index(tap2) {};
	int rand() { updateState(); return bits & 1; };

	int bitVal(int indexFromRight) {
		return (bits >> indexFromRight) & 1;
	}
};
