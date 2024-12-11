int gcd(int m, int n) {
  int tmp;
  while (m % n != 0) {
    tmp = n;
    n = m % n;
    m = tmp;
  }
  return n;
}

int main(void) {
  int N;
  int A[MAX_L];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  int L[MAX_L];
  L[0] = 0;
  for(int i = 1; i < N; i++) {
    L[i] = gcd(L[i-1], A[i-1]);
  }

  int R[MAX_L+1];
  R[N] = 0; 
  for(int i = N-1; i >= 0; i--) {
    R[i] = gcd(R[i+1], A[i]);
  }

  int ans = L[N-1];
  for(int i = 0; i < N-1; i++) {
    int tmp = gcd(L[i], R[i+1]);
    if(tmp > ans)
      ans = tmp;
  }

  printf("%d\n", ans);
  return 0;
}
