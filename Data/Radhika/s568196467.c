#include<stdio.h>
int main()
{
  int a[3],p=0,sum=0;
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  for(int i=0;i<3;i++){
   if(a[i]==5) p++;
   sum+=a[i];
  }
  if(p==2 && sum==17) printf("YES\n");
  else printf("NO\n");
  return 0;
}
