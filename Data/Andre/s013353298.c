#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x, n;
	int p[101] = { 0 };
	int result = 0;

	scanf("%d", &x);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a = 0;
		scanf("%d", &a);
		p[a] = 1;
	}

	int dif = 200;
	int num = 200;
	for (int i = 0; i <= 101; i++) {
		if (p[i] == 0) {
			if (abs(x - i) == dif) {
				if (i < num) {
					num = i;
				}
			}
			else if (abs(x - i) < dif) {
				dif = abs(x - i);
				num = i;
			}
		}
	}

	printf("%d", num);

	return 0;
}