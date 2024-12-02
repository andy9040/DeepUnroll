#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define int64 long long

int main()
{
	int64 aa, bb, cc, kk;
	scanf("%lld %lld %lld %lld", &aa, &bb, &cc, &kk);
	if(kk <= aa)
	{
		printf("%lld\n", kk);
		return 0;
	}
	ekse if(kk <= aa + bb)
	{
		printf("%lld\n", aa);
		return 0;
	}
	else
	{
		printf("%lld\n", (aa - (kk - aa - bb)));
		return 0;
	}
	return 0;
}