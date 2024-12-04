#include<stdio.h>

int n,q,A[2001],Q[201];

main(){

  int i,judge;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  for(i = 0; i < q; i++){
    scanf("%d",&Q[i]);
  }

  for(i = 0; i < q; i++){

    judge = solve(0,Q[i]);

    if(judge == 1){
      printf("yes\n");
    } else {
      printf("no\n");
    }

  }

  return 0;
 
}

int solve(int p, int t){
 
  if(t == 0){
    // printf("%d %d\n",p,t);
    return 1;
  } else if(t < 0){
    // printf("%d %d\n",p,t);
    return 0;
  } else if(p > n){
    // printf("%d %d\n",p,t);
    return 0;
  } else if(solve(p+1,t-A[p]) == 1){
    return 1;
  } else if(solve(p+1,t) == 1){
    return 1;
  }

}