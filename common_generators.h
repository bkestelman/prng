#pragma once
#include "multiplicative_congruential.h"

MultiplicativeCongruentialGenerator<int64_t> mersenneMinimalStandard();

MultiplicativeCongruentialGenerator<int64_t> RANDU(); // the infamous RANDU generator
