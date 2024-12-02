
#include<stdio.h>
#include<math.h>
int main(void) {
	int n, d;
	scanf("%d %d", &n, &d);
	int x[10][10];
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < d; i++) {
			scanf("%d",&x[j][i] );
		}
	}
	int c = 0;
	int sum = 0;
	double s;
	for (int i = 0; i < n; i++) {
		for (int m = i + 1; m < n; m++) {
			for (int j = 0; j < d; j++) {
				sum +=pow((x[i][j] - x[m][j]), 2);
			}
			s = sqrtf(sum);
			if (ceil(s) == floor(s)) {
				c++;
			}
			sum = 0;
		}
	}
	printf("%d\n", c);
	return 0;
}

