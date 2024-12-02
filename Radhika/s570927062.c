#include <stdio.h>
#include <string.h>

void chmax(int *a, int b){
  if(*a < b) *a = b;
}

/* void chmax(int *a, int b){ if(*a < b) *a = b; } */

int main(void){
  char s[3010], t[3010];
  scanf("%s", s);
  scanf("%s", t);

  int N, M;
  N = strlen(s);
  M = strlen(t);

  int dp[N+1][M+1];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(s[i] == t[j]) chmax(&dp[i+1][j+1], dp[i][j]+1);
      chmax(&dp[i+1][j+1], dp[i+1][j]);
      chmax(&dp[i+1][j+1], dp[i][j+1]);
    }
  }

  char tmp[3010];
  int num = 0;
  while(N > 0 && M > 0){
    if(dp[N][M] == dp[N-1][M]) N--;
    else if(dp[N][M] == dp[N][M-1]) M--;
    else{
      N--, M--;
      tmp[num++] = s[N];
    }
  }

  /* printf("%d\n", num); */
  char ans[num];
  for (int i = 0; i < num; i++) {
    ans[i] = tmp[strlen(tmp)-i-1];
  }

  printf("%s\n", ans);

  return 0;
}