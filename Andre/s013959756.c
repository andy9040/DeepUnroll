#include <stdio.h>

int main(void){
	int isPrime[123456*2+1];
	int i,j;
	isPrime[0]=0;
	isPrime[1]=0;
	for(i=2;i<=123456*2;i++){
		isPrime[i]=1;
	}
	for(i=2;i<=123456*2;i++){
		if(isPrime[i]){
			for(j=2;i*j<=123456*2;j++){
				isPrime[i*j]=0;
			}
		}
	}

	int n;
	while(scanf("%d",&n),n){
		i=0;
		for(j=n+1;j<=2*n;j++){
			i+=isPrime[j];
		}
		printf("%d\n",i);
	}

	return 0;
}