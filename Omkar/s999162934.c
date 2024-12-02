#include <stdio.h>

int gcd(int a, int b){
  if (b == 0){
    return a;
  }
  return gcd(b, a%b);
}

int main(){
  int N;
  scanf("%d", &N);
  int A[N];
  for(int i = 0; i < N; ++i){
    scanf("%d", &A[i]);
  }
  int ans = 0;
  for(int j = 0; j < N; ++j){
    int agcd = A[0];
    for(int k = 0; k < N; ++k){
      if(j != k){
        agcd = gcd(agcd, k);
      }
    }
    if(ans < agcd){
      ans = agcd;
    }
  }
  printf("%d",&ans);
}
