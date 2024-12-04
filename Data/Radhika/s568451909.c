#include<stdio.h>

int main(void){
	
	int n,p,d1,d2,i;
	int sum=0,sum_max=0,p_max;
	for(;;){
	scanf("%d",&n);
	if(n == 0)break;
	for(i=0;i<n;i++){
		sum=0;
		scanf("%d %d %d",&p,&d1,&d2);
		sum = d1 + d2;
		
		if(sum>sum_max){
			sum_max = sum;
			p_max = p;
		}
	}
	
	printf("%d %d\n",p_max,sum_max);
	}
return 0;
}