#include<stdio.h>

int main()
{

	char n;
	scanf("%c",&n);
	if(n>='a'&&n<'z'||n>'A'&&n<'Z')
	{
		printf("%c",n+1);
	}

}