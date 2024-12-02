#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//scanf("%d",&x);
//printf("%d",x);
//for(i=0;i<N;i++){  }
//if( == ){  }else{  }

int main()
{
	int N, i, k = 0,  Ans = 0;
	char W[100][10];

	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%s", &W[i]);

	for (int n = 1; n <= N; n++) {

		int l = strlen(W[n]);

			if (W[n - 1][l-1] == W[n][0]) {

			}//yes
			else {
				Ans++;
			}//no
	}
	int s , t ;

	for (s = 0; s < N; s++) {
		for (t = 0; t < N; t++) {
			if (strcmp(W[s],W[t])==0 && s!=t) {
				Ans++;
			}
		}
	}
	


	if (Ans >= 1) {
		printf("No");
	}
	if (Ans == 0) {
		printf("Yes");
	}


}
