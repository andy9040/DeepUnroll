#include <stdio.h>
#define M 13

int main(void)
{
  int i;
  char s[M];

  scanf("%s", s);

  for (i = 0; i < M; i++) {
    if (i == 4) {
      printf(" ");
    }
    printf("%c", s[i]);
  }
  printf("\n");

  return 0;
}
