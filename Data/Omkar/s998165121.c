#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int W[30],V[30],D,p,i,j,q=0,dp[30],l,r=0;
char c[3];
int main()
{
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	scanf("%d",&D);
	for(i=2;i--;)
	{
		scanf("%d",&j);
		l+=j;
		for(;j--;)
		{
			scanf("%s%d\n",c,&p);
			if(strcmp(c,"DD")*strcmp(c,"D")==0)
			{
				W[q]=strlen(c);
				V[q++]=p;
			}
		}
	}
	for(i=0;i<q;i++)
	{
		for(j=D;j>=W[i];j--)
			if(dp[j-W[i]]>=0)
			{
				dp[j]=dp[j]<dp[j-W[i]]+V[i]?dp[j-W[i]]+V[i]:dp[j];
				r=r>dp[j]?r:dp[j];
			}
	}
	printf("%d\n",r);
	return 0;
}