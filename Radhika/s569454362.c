#include <stdio.h>

int main(void){
	int A, B, N, NA;
	
	scanf("%d%d%d", &N, &A ,&B);
	
	NA = A * N;
	
	if(NA >= B){
		printf("%d", B);
	}else{
		printf("%d", NA);
	}
	
	return 0;
}