#include <stdio.h>

int main (void)
{
  int yen;
  int happy=0;
  
  scanf("%d", &yen);
   
  while (yen >= 500) {
    yen = yen - 500;
    happy += 1000;
  }
  
  while (yen >= 5) {
   yen = yen - 5;
   happy += 5;
  }
  
  printf("%d\n",happy);
  
  return 0;
}