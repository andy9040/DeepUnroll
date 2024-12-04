#include <stdio.h>
int n;
int A[20] = {0};
int q;
int m[200] = {0};


int solve(int search, int i) {
//	int j;
//	printf("%d %d\n", search, i);
	if (search == 0) return 1;
	if (i >= n || search < 0) return 0;

	return (solve(search, i + 1) || solve(search - A[i], i + 1));
}

int main(void)
{
	int i;
	
	scanf("%d", &n);	
	for (i = 0; i < n; ++i) {
		scanf(" %d", &A[i]);
	}

	scanf("%d", &q);
	for (i = 0; i < q; ++i) {
		scanf(" %d", &m[i]);
	}

	for (i = 0; i < q; ++i) {
		if (solve(m[i], 0)) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	
	return 0;
}