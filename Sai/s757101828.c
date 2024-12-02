#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
  return *(int*)b-*(int*)a;
}

int main()
{
  int n,h;
  
  scanf("%d%d",&n,&h);
  
  int a[n],b[n];
  int count=0;
  int i;
  
  for(i=0;i<n;i++)
  {
    scanf("%d%d",&a[i],&b[i]);
  }
  
  qsort(a,n,sizeof(int),cmp);
  qsort(b,n,sizeof(int),cmp);
 
  i=0;
  while(h>0)
  {
    if(i<n)
    {
     if(a[0]<b[i])
     {
       h-=b[i];
     }
     else
     {
       h-=a[0];
     }
    }
    else
    {
       h-=a[0];
    }
    i++;
    count++;
  }
  
  printf("%d\n",count);
  return 0;
}