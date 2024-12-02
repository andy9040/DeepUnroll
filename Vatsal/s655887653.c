#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	int n, k,a[200000],b[200000];
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < k; i++) {
		int flag = 1;
		for (int j = 0; j < n; j++) {
			int l = fmaxf(0, j - a[j]);
			int r = fminf(n - 1, j + a[j]);
			b[j]++;
			if (r + 1 < n) b[r + 1]--;
		}
		for (int j = 0; j < n - 1; j++) b[j + 1] += b[j];
		for (int j = 0; j < n; j++) {
			a[j] = b[j];
			if (a[j] != n) flag = 0;
		}
		if (flag==1) break;
	}
	for (int i = 0; i < k; i++) scanf("%d", a[i]);

	return 0;
}