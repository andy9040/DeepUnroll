#include<stdio.h>

int solve(int,int);
int n,A[20];

int main(){
  int i,q,m[200];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&m[i]);

  for(i=0;i<q;i++){
    if(solve(0,m[i]))printf("yes\n");
    else printf("no\n");
  }
  return 0;
}

int solve(int i,int m){
  int res;
  if(m<0)return 0;
  if(m==0)return 1;
  if(i==n)return 0;
  res = solve(i + 1, m) || solve(i + 1, m - A[i]);
  return res;
}