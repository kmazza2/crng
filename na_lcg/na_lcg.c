#include <assert.h>
#include "na_lcg.h"

const int IA = 16807;
const int IM = 2147483647;
const double AM = 1.0 / IM;
const int IQ = 127773;
const int IR = 2836;

struct na_lcg na_lcg_create(int seed) {
  struct na_lcg rng;
  assert(seed != 0);
  rng.state = seed;
  return rng;
}

double na_lcg_next(struct na_lcg *rng) {
  int k = rng->state / IQ;
  rng->state = IA * (rng->state - k * IQ) - IR * k;
  if (rng->state < 0) rng->state += IM;
  return AM * rng->state;
}
