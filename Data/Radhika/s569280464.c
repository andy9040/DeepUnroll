#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int ret = 0;
  for(int i = 0;i < n;i++) {
    int a;
    scanf("%d", &a);
    if(i % 2 == 0 && a % 2 == 1) {
      ret++;
    }
  }
  printf("%d\n", ret);
  return 0;
}