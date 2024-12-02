#include <stdio.h>

int main(void) {
	int W, H, N;
	int i;
	int l, r, d, u;
	if (scanf("%d%d%d", &W, &H, &N) != 3) return 1;
	l = 0; r = W; d = 0; u = H;
	for (i = 0; i < N; i++) {
		int x, y, a;
		if (scanf("%d%d%d", &x, &y, &a) != 3) return 1;
		switch (a) {
			case 1: if (l < x) l = x; break;
			case 2: if (x < r) r = x; break;
			case 3: if (d < y) d = y; break;
			case 4: if (y < u) u = y; break;
		}
	}
	printf("%d\n", r < l || u < d ? 0 : (r - l) * (u - d));
	return 0;
}
