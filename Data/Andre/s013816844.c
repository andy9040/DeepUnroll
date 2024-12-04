#include <stdio.h>
#include <math.h>

int main(void) {
	int D, E;
	while (scanf("%d%d", &D, &E) == 2 && (D > 0 || E > 0)) {
		int x;
		double answer = -1;
		for (x = 0; x <= D; x++) {
			int y = D - x;
			double cost = sqrt(x * x + y * y);
			double score = fabs(cost - E);
			if (answer < 0 || score < answer) answer = score;
		}
		printf("%.15f\n", answer);
	}
	return 0;
}