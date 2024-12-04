int main(void) {
	int N, C[499], S[499], F[499], ans[499], i, j;
	scanf("%d", &N);
	for (i = 0; i < N - 1; i++) {
		if (i != N - 1) scanf("%d %d %d", &C[i], &S[i], &F[i]);
		ans[i] = S[i] + C[i];
	}
	for (i = 0; i < N - 2; i++) {
		for (j = i + 1; j < N - 1; j++) {
			if (ans[i] >= S[j]) {
				if (ans[i] % F[j] == 0) ans[i] += C[j];
				else ans[i] += F[j] - (ans[i] % F[j]) + C[j];
			}
			else ans[i] = S[j] + C[j];
		}
	}
	for (i = 0; i < N - 1; i++) {
		printf("%d\n", ans[i]);
	}
	printf("0");


	return 0;
}