#include<stdio.h>
int main(void)
{
  int s,w;
  
  while(1<=s||s<=100)
  scanf("%d",&s);
  
  while(1<=w||w<=100)
  scanf("%d",&w);
  
  if(s<=w)
    printf("unseaf");
  else
    printf("seaf");
  
  return 0;
}