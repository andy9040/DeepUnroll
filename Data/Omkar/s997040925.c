#include<stdio.h>
#include<string.h>

int main()
{
  long int a,b,c,k,t;
  
  scanf("%ld", &a);
  scanf("%ld", &b);
  scanf("%ld", &c);
  scanf("%ld", &k);
  
  if(k <= a)
  {
    printf("%ld", k);
  }else if(k <= a + b)
  {
    t = a;
    printf("%ld", t);
  }
  else 
  {
    t = a - (k - (a + b));
    printf("%ld", t);
  }
  return 0; 
}