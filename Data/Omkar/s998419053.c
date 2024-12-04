#include <stdio.h>

int main(void) {
  int n, i, a, m = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a % 2 == 0) {
      if (a % 3 != 0) {
        if (a % 5 != 0) {
          m++;
        }
      }
    }
  }
  if (m == 0) {
    printf("APPROVED\n");
  } else
    printf("DENIED\n");
  return 0;
}