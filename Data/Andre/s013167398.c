#include <stdio.h>
#define N 2000
int solve(int , int);

int main()
{
  int i, j, n, q, m;
  int A[N], M[N];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&A[i]);
    }

  scanf("%d",&q);
  for(i = 0 ; i < q ; i++)
    {
      scanf("%d",&M[i]);
    }

  for(i = 0 ; i < q ; i++)
    {
      j = 0;
      if(solve(j, M[i])==1)
	{
	  printf("yes\n");
	}else if(solve(j, M[i])==0){
	printf("no\n");
    }
    }
 

  return 0;
}


int solve(int i, int m)
{
  int res;
  if(m==0) return 1;

  if(i>=n) return 0;
  res = solve(i + 1, m) || solve(i + 1, m - A[i]);

  
}