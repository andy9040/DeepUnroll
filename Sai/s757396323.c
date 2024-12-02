#include <stdio.h>
#include <stdlib.h>

#define N 100000

int compare(const void *a, const void *b) {
	int ia = *(int *) a;
	int ib = *(int *) b;

	return ia - ib;
}

long long gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	static int xx[N];
	int n, x, i, ans;

	scanf("%d%d", &n, &x);
	for (i = 0; i < n; i++)
		scanf("%d", &xx[i]);
	qsort(xx, n, sizeof *xx, compare);
	ans = abs(x - xx[0]);
	for (i = 0; i < n - 1; i++)
		ans = gcd(ans, abs(xx[i + 1] - x));
	printf("%d\n", ans);
	return 0;
}
