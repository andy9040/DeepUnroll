#include <stdio.h>

int main(void)
{
	int n, k;
	int i;

	scanf("%d%d", &n, &k);

	/*  */
	for (i = 0; n > 0; i++)
	{
		n /= k;
	}

	printf("%d\n", i);

	return 0;
}