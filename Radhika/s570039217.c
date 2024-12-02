#include <stdio.h>

int main(){
	int x[100], i=0;

	do{
	scanf("%d", &x[i]);
	i++;
	}while(x[i-1]!=0);
	i=0;

	while(x[i]!=0){
	printf("Case %d: %d\n", i+1, x[i]);
	i++;
	}
	return 0;
}