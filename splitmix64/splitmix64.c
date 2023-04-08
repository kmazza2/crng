#include <stdint.h>
#include "splitmix64.h"

struct splitmix64 splitmix64_create(uint64_t seed) {
    struct splitmix64 rng;
    rng.state = seed;
    return rng;
}

uint64_t splitmix64_next(struct splitmix64 *rng) {
	uint64_t z = ((rng->state) += 0x9e3779b97f4a7c15);
	z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
	z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
	return z ^ (z >> 31);
}

