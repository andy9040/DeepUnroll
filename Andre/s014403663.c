#include<stdio.h>
#include<string>

int main()
{
	char s;
	while(scanf("%c",&s)!=EOF)
		printf("%c",toupper(s));
	printf("\n");
}