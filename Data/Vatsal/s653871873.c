#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int x, n, p[100];
int resolvel(int a)
{
  if ( a<1 )
    return 999; // not found
  if ( !p[a-1] )
    return a;
  return resolvel(a-1);
}
int resolveh(int a)
{
  if ( a>100 )
    return 999; // not found
  if ( !p[a-1] )
    return a;
  return resolveh(a+1);
}
int main()
{
  scanf("%d %d", &x, &n);
  for ( int i=0; i<n; i++ ) {
    int num;
    scanf("%d", &num);
    p[num-1] = 1;
  }
  int l, h;
  l = resolvel(x);
  h = resolveh(x);
  printf("%d\n", abs(x-l)<=abs(x-h)? l: h);
  return 0;
}