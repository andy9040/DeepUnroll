#include <stdio.h>

int main() {
	int m, d;
	int cnt = 0, i, j;
	scanf_s("%d", &m);
	scanf_s("%d", &d);

	for (i = 4; i <= m; i++) {
		for (j = 22; j <= d; j++) {
			if ((j/10) > 1 && (j%10) > 1) {
				if ((j / 10) * (j % 10) == i) {
					cnt++;
				}
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}