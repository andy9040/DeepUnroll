#include <stdio.h>
int main(void)
{
	int N,D,a,ans;
	scanf("%d %d",&N,&D);
	a =(N-2)%(D*2+1);
	if (N <= D*4+2) {
		printf("2");
	} else {
		if (a<3) ans=(N-2)/(D*2+1)+1;
		printf("%d",ans);
		}
	return 0;
}