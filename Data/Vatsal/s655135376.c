#include <stdio.h>
int solve(int i,int m);
int A[20];
int n;
int main(){
  int i,q,m,ans;
  
  while(1){
    scanf("%d",&n);
    if(n>0 && n<=20) break;
    printf("Error\n");
    }
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || A[i] >2001) {
      printf("Error\n");
      }
  }
  while(1){
    scanf("%d",&q);
    if(q>0 && q<=200) break;
    printf("Error\n");
  }
  for(i=0;i<q;i++){
    scanf("%d",&m);
    ans = solve(0,m);
    if(ans == 1) printf("yes\n");
    else printf("no\n");
  }
  
  return 0;
}

int solve(int i,int m){
  int res;
  if(m == 0) return 1;
  if(i >= n) return -1;
  res = solve(i + 1,m) || solve(i+1,m-A[i]);
  return res;
}

