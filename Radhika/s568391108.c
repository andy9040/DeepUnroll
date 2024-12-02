#include <stdio.h>
int main(void) {
	int x, y;
	char c;
	int ans;
	while (1) {
		scanf("%d %c %d", &x, &c, &y);
		switch (c) {
		case '+': ans = x + y; break;
		case '-': ans = x - y; break;
		case '*': ans = x * y; break;
		case '/': ans = x / y; break;
		case '?': break;
		}
		if (c == '?')
			break;
		printf("%d\n", ans);
	}
	return 0;
}