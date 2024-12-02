/*
 * main.c
 *
 *  Created on: 2019/07/21
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int B[101] = {0};

int main()
{
	int N = 0, i = 0, ans = 0;
	scanf("%d", &N);
	for (i = 0; i < N-1; i++) {
		scanf("%d", &B[i]);
	}

	for (i = N-2; i >= 0; i-- ) {
		if (i == N-2) {
			ans += B[i];
		} else {
			if (B[i] > B[i+1]) {
				ans += B[i+1];
			} else {
				ans += B[i];
			}
		}
		//printf("%d\n", B[i]);
	}
	ans += B[0];
	printf("%d\n",ans);
    return 0;
}
