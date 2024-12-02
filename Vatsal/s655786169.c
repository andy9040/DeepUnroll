#include<stdio.h>
int main(){
  int a,b,c,k;
  scanf("%d%d%d%d",&a,&b,&c,&k);
  if(a >= k) printf("%d\n",k);
  else if(b >= k - a) printf("%d\n",a);
  else printf("%d\n",a - (k - a - b));
  return 0;
}