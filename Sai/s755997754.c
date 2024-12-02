#include <stdio.h>

int main(void)
{
	int point[1000],t,a =-1;
	while(point[a] != 0){
		a++;
		scanf("%d",&point[a]);
	}

	for(t=0;t<a;t++){
		printf("Case %d: %d\n",t+1,point[t]);
	}
	return 0;
}