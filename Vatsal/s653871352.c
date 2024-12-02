#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	int count = 0;
	double num = (double) n;

	while(num >= 1){
		num = num / (double)k;
		count++;
	}

	printf("%d\n", count);

	return 0;


}
