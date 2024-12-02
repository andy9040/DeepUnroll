#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

static size_t A[100000];

int compare_f(const void *a, const void *b) {
	return *((size_t *)a) < *((size_t *)b) ? -1 : 1;
}

static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	for (size_t i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

int main(void) {
	int32_t x[4], y[4];

	scanf("%"PRId32" %"PRId32" %"PRId32"%"PRId32, &x[0], &y[0], &x[1], &y[1]);

	x[2] = x[1] - (y[1] - y[0]);
	y[2] = y[1] + (x[1] - x[0]);
	x[3] = x[2] - (y[2] - y[1]);
	y[3] = y[2] + (x[2] - x[1]);
	printf("%"PRId32" %"PRId32" %"PRId32" %"PRId32"\n", x[2], y[2], x[3], y[3]);

	return 0;
}
