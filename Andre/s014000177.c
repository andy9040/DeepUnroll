#include <stdio.h>

int main(void){
  int charge,a;
  char line[5];

  fgets(line,4,stdin);
  sscanf(line,"%d",&a);

  while(a>=0){
    a = a - 1000;
  }
  charge = a * -1;
  printf("%d\n",charge);
}
