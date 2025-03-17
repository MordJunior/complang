#include <stdio.h>
#include <stdint.h>
#include "mordjunior_test.h"

extern uint64_t asma(uint8_t s[64]);

int main(void) {
	uint8_t test[64];
	FILE *rand = fopen("/dev/urandom", "r");

	for (int i = 0; i < TEST_RUNS; i++) {
		uint64_t exp = fill_array(test, 64, rand);
		uint64_t act = asma(test);

		if (exp != act) asm_failed(i, test, 64, exp, act);
	}

  fprintf(stdout, "Successfully ran %d tests.\n", TEST_RUNS);
}
