#include<stdio.h>
int n, A[50];
int solve (int i, int m){
if(m==0) return 1;
if(i>=n) return 0;
int R = solve(i+1, m) || solve(i+1,m-A[i]);
return R;
}
int main()[
int q, k, i;
scanf("%d", &n);
for(i=0;i<n;i++)
scanf("%d", &A[i]);
scanf("%d", &q);
for(i=0;i<q;i++){
scanf("%d", &k);
if(solve(0, k))
printf("yes \n");
else printf("no \n");
}
return 0;
}