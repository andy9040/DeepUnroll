#include<stdio.h>
#include<math.h>
int checkcan(long can)
{
  long m=floor(sqrt(can));
  if (m*m==can) return 1;
  return 0;
}
int main()
{
  int i,j,k,n,d,x[10][10];
  long can=0,dem=0;
  scanf("%d%d", &n, &d);
  for (i=0; i<n; i++)
    for (j=0; j<d; j++)
       scanf("%d", &x[i][j]);
  for (i=0; i<n; i++)
    { 
       for (k=i+1; k<n; k++)
         {
           can=0;
           for (j=0; j<d; j++)
             {
               can += (x[i][j]-x[k][j])*(x[i][j]-x[k][j]);
             }
           if (checkcan(can)==1) dem++;
         }
    }
  printf("%ld", dem);
  return 0;
}