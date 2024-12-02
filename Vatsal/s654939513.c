#include<stdio.h>

int n, A[50];

int main(){
  int q, m, i;
  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  for(i=0; i<q; i++) {
    scanf("%d", &m);
    if(Exhaustive(0,m)) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}

int Exhaustive(int i, int m){
  if(m==0) return 1;
  if(i>=n) return 0;
  int res Exhaustive(i+1, m) || Exhaustive(i+1, m-A[i]);
    return res;
}