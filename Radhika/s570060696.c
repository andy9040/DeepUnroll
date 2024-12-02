#include <stdio.h>
int main(void)
{
  int S,W;
  scanf ("%d %d",&S,&W);
  if (S>W) printf ("safe");
  if (S<=W) printf ("unsafe");
  return 0;
}