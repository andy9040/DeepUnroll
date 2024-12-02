#include <stdio.h>
#include <math.h>
#define MAXN 100+10
int main (void)
{
	int n;
	int a[MAXN];
	scanf("%d",&n);
	double sum = 0;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	sum/=(double) n;
	double min = 1e9;
	int t;
	for(int i=0;i<n;i++)
	{
		if(fabs(a[i]-sum)<min)
		{
			min = fabs(a[i]-sum);
			t = i;
		}
	}
	printf("%d\n",t);
	return 0;
}