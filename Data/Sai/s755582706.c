#include<stdio.h>
const int MAX=123456*2+1;
int P[MAX],F[MAX]={0},i,j,p=0,r;
int main()
{
	int N;
	for(i=2;i<MAX;i++)
		if(!F[i])
		{
			P[p++]=i;
			for(j=i*2;j<MAX;j+=i)
				F[j]=1;
		}
	for(;scanf("%d",&N)*N;)
	{
		for(i=r=0;i<p;i++)
			if(P[i]>N&&P[i]<=2*N)
				r++;
		printf("%d\n",r);
	}
	return 0;
}