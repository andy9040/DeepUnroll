#include<stdio.h>
int main()
{
	int A, B, C,K;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &K);

	if (K < A)
		printf("%d", K);
	else if (K <= A + B &&K>=A)
		printf("%d", A);
	else
		printf("%d",A - (K - A - B));

}