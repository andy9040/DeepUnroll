#include <stdio.h>
#include <string.h>
int main(void) {
  int K;
  char S[101];
  scanf("%d", &K);
  scanf("%s", S);
  int len = strlen(S);

  if (len <= K) {
    printf("%s\n", S);
  } else {
    for (int i = 0; i < K; i++) {
      printf("%c", S[i]);
    }
    printf("...\n");
  }
  return 0;
}