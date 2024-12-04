/* B - Easy Linear Programming */

#include <stdio.h>

int main(void){
  int A, B, C, K;
  scanf("%d %d %d %d", &A, &B, &C, &K);
  if(A == 0 && B == 0){
    printf("%d\n", (-1) * K);
  }else if(A == 0){
    if(K <= B){
      printf("0\n");
    }else{
      printf("%d\n", B - K);
    }
  }else if(K < A){
    printf("%d\n", K);
  }else if(K >= A && K <= A + B){
    printf("%d\n", A);
  }else{
    printf("%d\n", A - (K - (A + B)));
  }
}
