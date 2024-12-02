#include <stdio.h>

int main(void) {
  int n;
  int i;
  scanf("%d",&n);
  
  printf("%d",(1000-(n%1000))%1000);
  return 0;
}