#include <stdint.h>

struct splitmix64 {
    uint64_t state;
};

struct splitmix64 splitmix64_create(uint64_t);

uint64_t splitmix64_next(struct splitmix64 *);
