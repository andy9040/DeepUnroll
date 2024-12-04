#include<stdio.h>
int main(void){

	int N,X;
	int x[100000]={0};
	int i,j,tmp,a,b;
	
	scanf("%d%d",&N,&X);
	for(i=0;i<N;i++){
		scanf("%d",&x[i]);
	}
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(x[i]>x[j]){
				tmp=x[j];
				x[j]=x[i];
				x[i]=tmp;
			}
	}	}
	for(i=0;i<N;i++){
		if(x[i]<X){
			a=X-x[i];
			b=x[i+1]-X;
			break;
		}
		continue;
	}
	if(a==b)
		printf("%d",b);
	else if(a>b)
		printf("%d",b);
	else
		printf("%d",a);
	
	return 0;
}