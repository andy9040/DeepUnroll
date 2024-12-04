#include <stdio.h>

int main(void)
{	int a;
	int count = 0;
	scanf("%d",&a);
	if(a % 2)
		count += 1;
	if(a - 10 == 0 || a - 10 == 1||a - 10 ==100 || a - 10 == 101)
		count += 1;
	if(a - 100 > 0)
		count += 1;
	printf("%d\n",count);
}