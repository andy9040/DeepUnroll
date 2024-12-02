#include <stdio.h>
#include <stdlib.h>

int solve(int,int,int,int *);

int main(){
	int n, q, m, i;
	int *A;

	scanf("%d", &n);
	A = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &q);
	for(i = 0; i < q; i++){
		scanf("%d", &m);
		if(solve(0, m, n, A))
			printf("yes\n");
		else
			printf("no\n");
	}

	free(A);
	return 0;
}

int solve(int i, int m, int n, int *A){
	int res;

	if(m == 0)
		return 1;
	if(i >= n)
		return 0;
	res = solve(i+1, m, n, A) || solve(i+1, m-A[i], n, A);
	return res;
}
