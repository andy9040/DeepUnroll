#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, f;
	int z[10];
	while (1) {
		scanf("%d", &a);
		if (a == 0) {
			break;
		}
		b = 5;
		c = 0;
		while (a > b) {
			z[c] = b;
			b *= 5;
			c++;
		}
		e = 0;
		for (d = 0; d < c; d++) {
			e += (a / z[d]);
		}
		printf("%d\n", e);
	}
	
	return (0);
}