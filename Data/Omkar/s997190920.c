#include<stdio.h>
int main(){

  int A,B,N; 
  int sum1,sum2,min;
  1 <= N <=20;
  1 <= A <=50;
  1 <= B <=50;
  sum1 = A*N;
  sum2 = B*N;

  scanf("%d,%d,%d\n", N,A,B);
  if (sum1 >= sum2) {
    min = sum2;
    printf("%d\n", min);
  }
  else
   min = sum1;
   printf("%d\n", min);

   return 0;
}