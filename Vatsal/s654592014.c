#include <stdio.h>

int main() {
	int M[3][3], O[3][3];
	int bingo = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &M[i][j]);
		}
	}
	int N, X;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X);
	    for (int i = 0; i < 3; i++) {
		    for (int j = 0; j < 3; j++) {
		        if (M[i][j] == X) {
		        	O[i][j] = 1;
	            }
            }
		}
	}
	
	if (O[0][0] + O[1][1] + O[2][2] == 3 || O[0][2] + O[1][1] + O[2][0] == 3) {
		printf ("Yes\n");
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		if (O[i][0] + O[i][1] + O[i][2] == 3 || O[0][i] + O[1][i] + O[2][i] == 3) {
			printf ("Yes\n");
			return 0;
		}
	}
	printf ("No\n");
	return 0;
}