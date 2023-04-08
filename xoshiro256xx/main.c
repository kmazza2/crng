#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "xoshiro256xx.h"

#define NUM_IT 1000000

int main(void) {

  struct xoshiro256xx rng = xoshiro256xx_create(1,2,3,4);
  for (int i = 0; i < NUM_IT; ++i) {
    printf("%20.20g\n", xoshiro256xx_next(&rng));
}

return EXIT_SUCCESS;

}
