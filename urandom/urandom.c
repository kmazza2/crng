#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

uint64_t urandom_next(void) {
	int randomData = open("/dev/urandom", O_RDONLY);
	if (randomData < 0) {
		exit(EXIT_FAILURE);
	}
	uint64_t x;
	ssize_t bytes_read = read(randomData, &x,
		sizeof x);
	if (bytes_read < 0) {
		exit(EXIT_FAILURE);
	}
	int close_status = close(randomData);
	if (close_status != 0) {
		exit(EXIT_FAILURE);
	}
	return x;
}
