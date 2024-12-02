#include <stdio.h>

int main(void)
{
  int s1;
  int s2;
  int s3;
  int s;
  
  scanf("%d", &s1);
  scanf("%d", &s2);
  scanf("%d", &s3);
  
  s = s1 + s2 + s3;
  printf("%d", s);
  
  return (0);
}