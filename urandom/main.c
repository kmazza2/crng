#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "urandom.h"

int main(void) {

	for (int i = 0; i < 1000000; ++i) {
		printf("%" PRIu64 "\n", urandom_next()); 
	}

	return EXIT_SUCCESS;

}
