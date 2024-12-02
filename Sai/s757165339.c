#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", (a - b * 2 > 0) ? a - b * 2 : 0);
	return 0;
}
