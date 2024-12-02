#include<stdio.h>
int A[2000],M[2000],i,q,n,count=0;

int solve(int p,int t){
  if(p >= n){return 0;}
if(t==A[p]){
printf("yes\n");
 return 1; 
 }else if(t-A[p] < 0){
  return 0;
 }
 if(solve(p+1,t-A[p]))return 1;

 if(solve(p+1,t)) return 1;

 return 0;
}
int main(){
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&A[i]);
}
scanf("%d",&q);
for(i=0;i<q;i++){
scanf("%d",&M[i]);
}
 for(i = 0; i < q;i++){
   if(!solve(0,M[i])){
printf("no\n");
   }
 }
   // count++;
   // }
return 0;
}