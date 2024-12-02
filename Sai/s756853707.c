#include "stdio.h"

int gojo(int, int);

int main(void){
  int N, A[100000], r, rmax;
  scanf("%d\n", &N);
  for(int i = 0;i < N;i++){
    scanf("%d ", &A[i]);
  }
  r = A[1];
  for(int j = 2;j < N;j++){
      r = gojo(r, A[j]);
  }
  rmax = r;
  for(int i = 1;i < N;i++){
    r = A[0];
    for(int j = 1;j < N;j++){
      if(j != i){
        r = gojo(r, A[j]);
      }
    }
    if(rmax < r){
      rmax = r;
    }
  }
  printf("%d", rmax);
  return 0;
}

int gojo(int a, int b){
  int r;
  if(a < b){
    r = b;
    b = a;
    a = r;
  }
  while(1){
    if(a % b == 0){
      break;
    }else{
      r = a % b;
      a = b;
      b = r;
    }
  }
  return b;
}