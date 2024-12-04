#include<stdio.h>

int main(void)
{
	int i,a;
	int com[3000];
	for(i=0;;i++){
		scanf("%d",&com[i]);
		if(com[i]==0)break;
	}
	a=i;
	for(i=0;a>i;i++){
		printf("Case %d : %d\n",i+1,com[i]);
	}
	return 0;
}