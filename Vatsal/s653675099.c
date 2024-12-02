#include<stdio.h>

void rec(int,int,int*);
int n,q,r=0;

int main(){
  int i,j;
  int pp;
  
  scanf("%d",&n);
  int A[n];
  char tt;

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  int m[q];
  for(i=0;i<q;i++){
    scanf("%d",&m[i]);
  }
  for(i=0;i<q;i++){
    pp=0;
    r=0;
    for(j=0;j<n;j++){
      if(A[j]==m[i])pp++;
    }
    if(pp==0)rec(0,m[i],A);
    if(r==0)printf("no\n");
  }
  return 0;
}

void rec(int i,int m,int *A){
  if(m==0){
      printf("yes\n");
      r++;
      return;
  }
  if(i>=n)return;
  rec(i+1,m,A);
  rec(i+1,m-A[i],A);
  return; 
}

