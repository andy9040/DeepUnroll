#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int na[1000];
	double sig;
	while (1)
	{
		int n, i;
		double sum = 0;
		memset(na, 0, sizeof(int)*1000);
		
		scanf("%d", &n);
		if (n == 0)
			break;
		
		for (i = 0; i < n; i++)
		{
			int s = 0;
			scanf("%d", &s);
			na[i] = s;
			sum += s;
		}
		
		sig = 0;
		for (i = 0; i < n; i++)
		{
			sig += (pow(na[i] - (sum/n), 2));
		}
		printf("%.8f\n", sqrt(sig / n));
	}
	
	return 0;
}