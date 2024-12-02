#include<stdio.h>
#include<math.h>
double temp[10000][10000];
int main(void)
{
	int a,b;
	scanf("%d %d",&a,&b);
	int i,j,k;
	int count = 0;
	double sum = 0;
	double c = 0;
	for(i = 0;i<a;i++)
		for(j = 0;j<b;j++)
			scanf("%lf",&temp[i][j]);
	getchar(); 
	
	for(i = 0;i<a;i++)
	{
		for(j = i+1;j<a;j++)
		{
			for(k = 0;k<b;k++)
				sum += (temp[j][k] - temp[i][k]) * (temp[j][k] - temp[i][k]);
			c = sqrt(sum);
			if(c-(double)(int)c < 1e-6) count++;
			sum=0;
		}
	} 
	printf("%d",count);
	return 0;
}