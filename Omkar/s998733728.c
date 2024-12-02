#include <stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	long long int N, W, i, j;
	long long int w[101], v[101];
	long long int C[101][101];
	
	scanf("%lld%lld", &N, &W);
	
	for(i = 1; i <= N; i++){
		scanf("%lld%lld", &w[i], &v[i]);
	}
	
	for(j = 1; j <= N; j++) C[0][j] = 0;
	for(i = 1; i <= W; i++) C[i][0] = 0;
	
	for(i = 1; i <= N; i++){
		for(j = 1; j <= W; j++){
			if(j < w[i]) C[i][j] = C[i-1][j];
			else C[i][j] = max(C[i-1][j], C[i - 1][j - w[i]] + v[i]);
		}
	}

	printf("%lld\n", C[N][W]);
	return 0;
}