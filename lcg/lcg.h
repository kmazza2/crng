#include <inttypes.h>

struct lcg {
  uint64_t state;
};

struct lcg lcg_create(uint64_t);

double lcg_next(struct lcg *);
