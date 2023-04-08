#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "splitmix64.h"

int main(void) {

	struct splitmix64 rng = splitmix64_create(1);
	for (int i = 0; i < 10000000; ++i) {
		printf("%" PRIu64 "\n", splitmix64_next(&rng));
	}
	return EXIT_SUCCESS;

}
