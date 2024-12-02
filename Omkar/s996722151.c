#include <stdio.h>
#include <corecrt_math_defines.h>
#include <math.h>

int main(void)
{
	int n, d, i, j, k;
	int sumCoordinate = 0;
	int count = 0;
	int x[10][10];

	scanf("%d%d", &n, &d);

	for (i = 0; i < n; i++) {
		for (j = 0; j < d; j++) {
			scanf("%d", &x[i][j]);
		}
	}

	//座標の距離を調べる
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = 0; k < d; k++) {
				//座標の差を合計する(sumCoordinate)
				sumCoordinate += (x[j][k] - x[i][k]) * (x[j][k] - x[i][k]);
			}
			//sumCoordinateの平方根が整数か調べる
			if (sqrt(sumCoordinate) == (int)sqrt(sumCoordinate)) {
				count++;//整数ならカウント
			}
			sumCoordinate = 0;
		}
	}
	
	printf("%d\n", count);

	return 0;
}