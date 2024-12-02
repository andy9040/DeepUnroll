#include <stdio.h>

int main(){

	int x, y, z;
	int divisao;
	
	scanf("%d%d%d", &x, &y, &z);
	
	divisao = x/(y+z);
	
	if ((divisao * (y+z)) + z <= x){
		printf("%d\n", divisao);
	} else {
		printf("%d\n", divisao - 1);
	}
		
	return 0;
}
