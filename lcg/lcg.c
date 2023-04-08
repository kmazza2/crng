#include <assert.h>
#include <inttypes.h>
#include "lcg.h"

struct lcg lcg_create(uint64_t seed) {
  struct lcg rng;
  assert(seed != 0);
  rng.state = seed;
  return rng;
}

double lcg_next(struct lcg *rng) {
  rng->state = (16807 * rng->state) % 2147483647;
  return (rng->state) / 2147483647.0;
}
