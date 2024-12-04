#include <stdio.h>

int main(void){
	int n, a, b, c, i;
	while (1){
		scanf("%d", &n);
		if (n == 0) break;
		for (i =0; i < n; i++){
			scanf("%d%d%d", &a, &b, &c);
			if ((a == 100 || b == 100 || c == 100) || (a + b)/2.0 >= 90 || (a + b + c)/3.0 >= 80){
				printf("A\n");
			}else if ((a + b + c)/3.0 >= 70 || (a + b + c)/3.0 >= 50 && a >= 80 || b >= 80){
				printf("B\n");
			}else printf("C\n");
		}
	}
	return 0;
}