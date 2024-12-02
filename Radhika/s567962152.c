#include<stdio.h>

int main() {
	int A, B, C = 0;

	scanf_s("%d %d %d", &A, &B, &C);

	if (A==B==5,C==7 ||B==C==5,A==7 || A==C==5,B==7  ) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}