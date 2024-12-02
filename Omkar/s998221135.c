#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if((a>=2&&a<=13)&&(b>=2&&b<=13))
	{
		if(a>b)
			printf("Alice\n");
		else if(a<b)
			printf("Bob\n");
		else if(a==b)
			printf("Draw\n");
	}
	else if(a==1&&(b>=2&&b<=13))
	{
		printf("Alice\n");
	}
	else if(b==1&&(a>=2&&a<=13))
		printf("Bob\n");
	else if(a==1&&b==1)
		printf("Draw\n");
	return 0;
}