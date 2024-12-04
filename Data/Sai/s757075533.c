#include<stdio.h>
#include<math.h>

int main() {
	int i, j, k;
	int	n, m, h, g, a, b, c, d;
	int f = 0;
	int x[15][15];
	int w;

	scanf("%d %d", &n, &d);

	for (i = 0;i < n;i++) {
		for (j = 0;j < d;j++) {
			scanf("%d", &x[i][j]);
		}
	}

	for (i = 0;i < n;i++) {
		for (j = i+1;j < n;j++) {
			h = 0;
			for (k = 0;k < d;k++) {
				h = h + (x[i][k] - x[j][k])*(x[i][k] - x[j][k]);
			}
			w = sqrt(h);
			if (w*w == h) {
				f = f + 1;
			}
		}
	}

	printf("%d",f);


	return 0;
}