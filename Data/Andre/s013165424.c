#include <stdio.h>

int main(void) {
	char a[3], b[3];
	int n, i, point;
	
	while (1) {
		point = 0;
		scanf("%d", &n);
		if (n == 0) break;
		
		while (n > 0) {
			if (n != 1) {
				scanf("%s", a);
				scanf("%s", b);
					if (a[0] != b[0])
						point++;
			}
			else
				scanf("%s", a);
			n -= 2;
		}
		printf("%d\n", point);
	}
	
	return 0;
}