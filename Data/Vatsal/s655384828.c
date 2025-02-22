#include <stdio.h>

int n;
int a[20];

int solve(int,int);

int main(){
  int q,i,m;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&m);
    m = solve(0,m);
    if(m == 1) printf("yes\n");
    else printf("no\n");
  }

  return 0;  
}

int solve(int i,int m){
  int res = 0;
  if(m == 0) return 1;
  if(i >= n) return 0;
  res = solve(i + 1, m) || solve(i + 1, m - a[i]);
  return res;
}

