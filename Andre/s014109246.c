#include<stdio.h>

int main() {
	int a, b, c;
	int flag = 0;
	int k;
	
	scanf("%d%d%d%d", &a, &b, &c, &k);

	for (int i = 0; i < k; i++) {
		flag = 0;

		if (b > a) {
			flag++;
		}
		else {
			b *= 2;
		}

		if (c > b) {
			flag++;
		}
		else {
			c *= 2;
		}

		if (flag == 2) {
			puts("Yse");
			return 0;
		}
	}

	puts("No");

	return 0;
}
