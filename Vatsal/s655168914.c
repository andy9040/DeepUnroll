#include <stdio.h>
int main(void)
{
	char x,y;
	int X,Y;
	int a=10,b=11,c=12,d=13,e=14,f=15;
	while(scanf("%c %c",&x,&y)!=EOF)
	{
		X=x;
		Y=y;
		if(X<Y)
			printf("<\n");
		if(X>Y)
			printf(">\n");
		if(X==Y)
			printf("=\n");
		getchar();	
	}
	return 0;
 } 