#include<stdio.h>

int d, l;

int main(void)
{
	int ans;
	
	scanf( "%d %d", &d, &l );
	
	ans = d / l;
	ans += d % l;
	
	printf( "%d\n", ans );
	
	return 0;
}