#include<stdio.h>
#define true 1
#define false 0

int A[20],n;

int solve(int i,int m){
  int res;
if(m == 0) return true;

if(i >= n) return false;

res = solve(i + 1, m) || solve(i + 1, m - A[i]);
return res;
   }


int main(){
  int q,m[200];
  int i;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);


  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&m[i]);
  }

   for(i=0; i<q; i++){
     if(solve(0,m[i])==true) printf("yes\n");
     else printf("no\n");
  }

   return 0;
}


