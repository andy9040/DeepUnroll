#include <stdio.h>

int main()
{
	int n;
	int a;
	int count = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (i % 2 != 0 && a % 2 != 0)
			count++;
	}

	printf("%d\n", count);

	return 0;
}