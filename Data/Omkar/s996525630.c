#include<stdio.h>

#define MAX   20
#define N 200

int solve(int,int);

int n;
int A[MAX];

int main()
{
  int q,i,res;
  int B[N];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  for(i = 0; i < q; i++){
    scanf("%d",&B[i]);
  }

  for(i = 0; i < q; i++){
    res = solve(0,B[i]);
    if(res == 1){
      printf("yes\n");
    }
    else if(res == 0){
      printf("no\n");
    }
  }

  return 0;
}

/*1 solve(i, m)
2   if m == 0
3     return true
4   if i >= n
5     return false
6   res = solve(i + 1, m) || solve(i + 1, m - A[i])
7   return res*/

int solve(int i,int m)
{
  int res;
  if(m == 0) return 1;
  if(i >= n) return 0;
  if(solve(i+1,m) == 1 || solve(i+1,m - A[i]) == 1){
    return 1;
  }
  return 0;
}

