#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
int main() {
	unsigned i, n, cnt,f;
	while (scanf("%u", &n), n != 0) {
		cnt = 0,f=5;
		while (1) {
			if(f<=n)cnt += n / f;
			else break;
			f *= 5;
		}
		printf("%u\n", cnt);
	}
	return 0;
}