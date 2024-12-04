#include<stdio.h>
#include<math.h>
int main() {
  int a, b, c, d, l, n, x, z;
  scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
  n = ceil((double)a / (double)c);
  x = ceil((double)b / (double)d);
  if(n >= x) {
    z = l - n;
  }else{
    z = l - x;
  }
  printf("%d\n", z);
  return 0;
}