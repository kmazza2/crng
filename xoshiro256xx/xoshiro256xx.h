#include <stdint.h>

struct xoshiro256xx {
    uint64_t state[4];
};

struct xoshiro256xx xoshiro256xx_create(
  uint64_t s0,
  uint64_t s1,
  uint64_t s2,
  uint64_t s3
);

double xoshiro256xx_next(struct xoshiro256xx *rng);
