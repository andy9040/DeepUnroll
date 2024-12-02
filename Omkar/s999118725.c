#include <stdio.h>

int A[20];
int n;

int solve(int p, int t);
int sort(void *a, void *b);

int main(void) {
	int i, q, M;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	
	qsort(A, n, sizeof(A[0]), sort);
	
	scanf("%d", &q);
	for (i = 0; i < q; ++i) {
		scanf("%d", &M);
		if (solve(-1, M)) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	
	return 0;
}

int solve(int p, int t) {
	if ((p == n) || (t == 0)) return t == 0;
	if (A[p + 1] > t) return 0;
	if (solve(p + 1, t - A[p + 1])) return 1;
	return solve(p + 1, t);
}

int sort(void *a, void *b) {
	return *(int*)a - *(int*)b;
}