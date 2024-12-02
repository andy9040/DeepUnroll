#include <stdio.h>

int main(void)
{
	int x;
	int c;
	
	c = 1;
	x = 1;
	while (x != 0){
		scanf("%d", &x);
		if (x != 0){
			printf("Case %d: %d\n", c, x);
		}
		c++;
	}
	
	return (0);
}