#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S[100001];

int main() {
  int N, K, result;
  int i;
  scanf ("%d %d", &N, &K);
  scanf ("%s", S);
  result = 0;
  for (i=1;i<N;i++) {
    if (S[i]==S[i-1]) {
    	result++;
    }
  }
  
  result += K*2;
  if (result >= N) result = N-1;
  
  printf("%d", result);
  return 0;
}


