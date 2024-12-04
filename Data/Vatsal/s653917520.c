#include <stdio.h>
#include <string.h>
#define SIZE 101
int main() {
	int num, i, cmp;
	int taro = 0, hanako = 0;
	char tcard[SIZE], hcard[SIZE];
	scanf(" %d", &num);
	for (i = 0; i < num; i++) {
		scanf("%100s %100s", tcard, hcard);
		cmp = strcmp(tcard, hcard);
		if (cmp > 0) {
			taro += 3;
		} else if (cmp == 0) {
			taro += 1;
			hanako += 1;
		} else {
			hanako += 3;
		}
	}
	printf("%d %d\n", taro, hanako);
	return 0;
}