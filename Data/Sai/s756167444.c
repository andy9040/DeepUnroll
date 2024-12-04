#include<stdio.h>
 
#define N 2000
int solve(int,int);
 
int A[N],n;
main(){
  int i,j,q,x,m[N];
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&m[i]);
  }
  for(i=0;i<q;i++){
    x= solve(0,m[i]);
   if(x==1){
     printf("yes\n");
     x=0;
   }
   else{
     printf("no\n");
   }
  }
  return 0;
}
 
int solve(int i,int m){
  int res;
  if(m==0){
    return 1;
  }
  if(i>n){
    return 0;
  }
  else{
    res = solve(i+1,m)||solve(i+1,m-A[i]);
    return res;
  }
}