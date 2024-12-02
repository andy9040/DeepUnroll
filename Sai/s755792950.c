#include <stdio.h>

int main() {
	int A,B,C,K,i;
	scanf("%d %d %d %d", &A, &B, &C, &K);
		if (K <= A + B) {
			printf("%d", A);
		}
		else{
			printf("%d", A - (K - A - B));
		}
	return 0;
}