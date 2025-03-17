#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_RUNS 245120

uint64_t fill_array(uint8_t dst[], size_t n, FILE *rng) {
 uint64_t res = 0;
 for (size_t i = 0; i < n; i++) {
   dst[i] = fgetc(rng);
   if (dst[i] >= '0' && dst[i] <= '9') res++;
 }
 return res;
}

size_t get_size(FILE *rng) {
  size_t res = 0;
  for (size_t i = fgetc(rng); i > 0; i--)
    res += fgetc(rng);
  return res;
}

void asm_failed(int i, uint8_t data[], size_t n, uint64_t exp, uint64_t act) {
  FILE *dump = fopen("dump.csv", "w");
  fprintf(stderr, "Test %d with %zu items failed. Expected %lu, got %lu.\n", i, n, exp, act);
  fprintf(dump, "%d;%zu;%lu;%lu\n", i, n, exp, act);
  for (size_t j = 0; j < n; j++) {
    fprintf(dump, "%d\n", data[j]);
  }
  fflush(dump);
  fclose(dump);

  exit(i);
}
