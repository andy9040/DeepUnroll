#include <stdio.h>

int main()
{
	int a[3];
	for (int i = 0; i < 3; ++i)
	{
		scanf("%d", &a[i]);
	}

	if (a[0] + a[1] + a[2] != 17)
		printf("NO");

	else if (a[0] == 7 || a[1] == 7 || a[2] == 7)
	{
		if (a[0] == 5 || a[1] == 5 || a[2] == 5)
			printf("YES");
		else
			printf("NO");
	}
	else
		printf("NO");

	return 0;
}