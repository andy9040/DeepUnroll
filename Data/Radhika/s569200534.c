#include<stdio.h>

int main()
{
	int x, happy=0;
	scanf("%d", &x);
	while (x >= 500) {
		x -= 500;
		happy += 1000;
	}
	while (x >= 5) {
		x -= 5;
		happy += 5;
	}
	printf("%d", happy);
	return 0;
}