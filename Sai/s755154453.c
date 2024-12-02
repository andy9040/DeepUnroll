#include <stdio.h>

int main(void)
{
  long int x, a, result = 0;
  
  scanf("%ld", &x);
  
  a = x % 500;
  result += ( x / 500 ) * 1000 + ( a / 5 ) * 5;
  
  printf("%Ld", result);
      return 0;
}