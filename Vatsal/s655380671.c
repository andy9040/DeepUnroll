#include<stdio.h>
int main(){
	int N;
	scanf("%d", &N);
	int q = N % 1000;
	printf("%d", q > 0 ? 1000 - q : 0);
	return 0;
}