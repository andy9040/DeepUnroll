#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	int k, i;
	char S[101];
	char S1[101];
	char S3[4] = "...";
	//char ch;
	scanf("%d",&k);
	scanf("%s", S);
	i = strlen(S) ;
	//printf("%d %s",i,S);
	//S[i]='\0';
	if (i<=k)
		printf("%s",S);
	else
	{
		for(i=0;i<k;i++)
			printf("%c",S[i]);
		printf("...");
	}
	return 0;
	
}