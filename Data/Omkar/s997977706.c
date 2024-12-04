#include <stdio.h>

#define LENGTH 256

int charge(int key){
int i,c;
for(i=0;i<11;i++){
  c= 1000 * i -key;
  if(c>0){
  return c;
  }
}
}

int main(void) {
 char input[LENGTH];
 int C,N;
 while(1){
  printf("amount: ");
  fgets(input, LENGTH-1, stdin);
  sscanf(input, "%d", &N);
 if((N<1) || (N>10000)) break;
  C = charge(N);
  printf("%d yen.\n" ,C);
 }
}
