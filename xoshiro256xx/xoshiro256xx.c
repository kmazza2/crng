#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "xoshiro256xx.h"

static inline uint64_t rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

struct xoshiro256xx xoshiro256xx_create(
    uint64_t s0,
    uint64_t s1,
    uint64_t s2,
    uint64_t s3
) {
  struct xoshiro256xx rng;
  assert(
    s0 != 0 || 
    s1 != 0 || 
    s2 != 0 || 
    s3 != 0
  );
	rng.state[0] = s0;
	rng.state[1] = s1;
	rng.state[2] = s2;
	rng.state[3] = s3;
        return rng;
}

static uint64_t xoshiro256xx_next_uint64_t(struct xoshiro256xx *rng) {
	const uint64_t result = rotl((rng->state)[1] * 5, 7) * 9;

	const uint64_t t = (rng->state)[1] << 17;

	(rng->state)[2] ^= (rng->state)[0];
	(rng->state)[3] ^= (rng->state)[1];
	(rng->state)[1] ^= (rng->state)[2];
	(rng->state)[0] ^= (rng->state)[3];

	(rng->state)[2] ^= t;

	(rng->state)[3] = rotl((rng->state)[3], 45);

	return result;
}

double xoshiro256xx_next(struct xoshiro256xx *rng) {
	uint64_t x = xoshiro256xx_next_uint64_t(rng);
	return ((x >> 11) * 0x1.0p-53);
}
