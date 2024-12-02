#include <stdio.h>

#define MAX 2000

int solve(int,int,int *,int);

int main() {
  int n,q;
  int A[MAX],m[MAX];
  int i;

  scanf("%d", &n);
  for ( i = 0; i < n; i++) {
    /* code */
    scanf("%d", &A[i]);
  }
    scanf("%d", &q);
  for ( i = 0; i < q; i++) {
    /* code */
    scanf("%d", &m[i]);
  }
  for (i = 0; i < q; i++) {
    /* code */
    if(solve(0,m[i],A,n)){
      printf("yes\n");
    }else{
      printf("no\n");
    }
  }



  return 0;
}

int solve(int i,int m,int *A,int n){
  int res=0;

  if (m==0) {
    /* code */
    return 1;
  }else if(i>=n){
    /* code */
    return 0;

  }else if(solve(i+1,m,A,n) || solve(i+1,m-A[i],A,n)){

    return 1;

  }else {

    return 0;
  }

}

