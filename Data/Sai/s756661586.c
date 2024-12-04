#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>


int main()
{
  int cnt;
  int a,b,c;
  int i;

  cnt = scanf("%d %d %d", &a, &b, &c);

  if (a < b) {
    if ((a <= c) &&
        (c <= b)) {
      printf("Yes");
      return 0;
    } else {
      printf("No");
      return 0;
    }
  }

  if ((b <= c) &&
      (c <= a)) {
    printf("Yes");
    return 0;
  } else {
    printf("No");
    return 0;
  }

  return 0;
}
