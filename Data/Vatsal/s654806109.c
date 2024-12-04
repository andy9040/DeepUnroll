#include <stdio.h>

int main(void){
	int sp=0,sq=0;
	int n,count=0;
	int p[30],q[30];
	while(scanf("%d",&n)!=EOF){
		if(n!=0){
			p[sp++]=n;;
			count=count+1;
		}else if(n==0){
			q[sq++]=p[--sp];
		}
	}
	for(sp=1;sp<=count;sp++){
		printf("%d\n",q[sp]);
	}
	return 0;
}