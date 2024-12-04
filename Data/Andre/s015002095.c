#include <stdio.h>
int main(void)
{
  int a[1000];
  int i, n;

  for(i=0;i < 256;i++){
    scanf("%d", &a[i]);
    if(a[i] == 0)break;
  }
  n=i;
  for(i=0;i<n;i++){
  if(a[i] == 0)break;
    printf("Case %d: %d\n", i+1, a[i]);
 }
  return 0;
}