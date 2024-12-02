#include<stdio.h>
int main(void)
{
	int x,y,a,b,c;
	scanf("%d",&x);
	a=x%100;
	b=x%10;
	c=x%1;
	y=a+b+c;
	printf("%d\n",y);
	return 0;
}