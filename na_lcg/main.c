#include <stdio.h>
#include <stdlib.h>
#include "na_lcg.h"

int main(void) {
  struct na_lcg my_rng = na_lcg_create(1);
  for (int i = 0; i < 1000000; i++) {
    printf("%g\n", na_lcg_next(&my_rng));
  }
  return EXIT_SUCCESS;
}
