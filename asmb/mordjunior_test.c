#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mordjunior_test.h"

extern uint64_t asmb(uint8_t src[], size_t n);

#define MAX_LENGTH (UCHAR_MAX * UCHAR_MAX) 

int main(void)
{
  uint8_t *data = malloc(sizeof(uint8_t) * MAX_LENGTH);
  FILE *random = fopen("/dev/urandom", "r");
  
  for (int i = 1; i < TEST_RUNS; i++) {
    size_t size = get_size(random);    
    uint64_t exp = fill_array(data, size, random);
    uint64_t act = asmb(data, size);

    if (exp != act) asm_failed(i, data, size, exp, act);
  }

  fprintf(stdout, "Successfully ran %d tests.\n", TEST_RUNS);

  free(data);
  return EXIT_SUCCESS;
}
