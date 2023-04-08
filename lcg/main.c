#include <stdio.h>
#include <stdlib.h>
#include "lcg.h"

#define NUM_IT 1000000

int main(void) {
  struct lcg my_rng = lcg_create(1);
  for (int i = 0; i < NUM_IT; i++) {
    printf("%g\n", lcg_next(&my_rng));
  }
  return EXIT_SUCCESS;
}
