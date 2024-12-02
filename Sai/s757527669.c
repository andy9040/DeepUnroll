#include <stdio.h>

int main(void)
{
	int a,b,c,sum;
	sum = 0;
	
	scanf("%d", &a);
	
	while(a > 0){
		scanf("%d%d", &b, &c);
		sum = sum + c - b + 1;
		a--;
	}
	printf("%d", sum);
	
	return 0;
}
