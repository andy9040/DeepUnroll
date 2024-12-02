#include<stdio.h>
int main()
{
  int a,b,c,k,i,s=0;
  scanf("%d",&a);
   scanf("%d",&b);
   scanf("%d",&c);
   scanf("%d",&k);
  if(k!=0 && a!=0)
  {
  for(i=1;i<=k;i++)
  {
    if(k<a)
      s=s+1;
  }
  }
  k=k-a;
  if(k!=0 && b!=0)
  {
  for(i=1;i<=k;i++)
  {
    if(k<b)
      s=s+0;
  }
  }
  k=k-b;
  if(k!=0 && c!=0)
  {
  for(i=1;i<=k;i++)
  {
    if(k<c)
    s=s-1;
  }
  }
  printf("%d",s);
}