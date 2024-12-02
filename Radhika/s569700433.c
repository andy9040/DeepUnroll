#include <stdio.h>

int main(void)
{
	int i,N,X,x[100000],min,max;
	scanf("%d %d",&N,&X);
	for(i=0;i<N;i++){
		scanf("%d",&x[i]);
	}
	min=x[0];
	max=x[0];
	for(i=0;i<N;i++){
		if(x[i]<min){
			min=x[i];
		}
		if(x[i]>max){
			max=x[i];
		}
	}
	if(X-min<max-X){
		printf("%d\n",abs(X-min));
	}else{
		printf("aaa%d\n",abs(max-X));
	}
	
	return 0;
}
