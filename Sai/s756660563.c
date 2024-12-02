#include <stdio.h>

int main() {
	int a, b;

	scanf("%d%d", &a, &b);
	printf(a == b ? "Draw\n" : a == 1 || (b != 1 && a > b) ? "Alice\n" : "Bob\n");
	return 0;
}
