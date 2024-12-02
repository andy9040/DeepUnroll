#include <stdio.h>

int main()
{
  long int x, ans = 0;
  int a = 1000000000;
  int b;
  int i = 0;
  int c[8];
  scanf("%ld", &x);
  for(i = 0; i < 7; i++){
    b = x / a;
    c[i] = b * a / 500;
    x = x - (b * a);
    a = a / 10;
  }
  c[8] = x / 5;
  for(i = 0; i < 7; i++){
    ans += c[i] * 1000;
  }
  ans += c[8] * 5;
  printf("%ld\n", ans);
  
  return 0;
}