#include <stdio.h>
int main() {
	int s[3],i;
	int count = 0;

	scanf_s("%d%d%d", &s,3);

	for (i = 0; i < 3; i++) {
		if (s[i] == 1) count += count + 1;
	}

	printf("%d", count);
	return 0;
}