#include <stdio.h>

int	main(void)
{
  int	a;
  int	b;
  int	c;
  int	k;
  int	i;
  
  i = scanf("%d %d %d", &a, &b, &c);
  i = scanf("%d", &k);
  i = 0;
  while (a < b)
  {
  	b *= 2;
    i++;
  }
  while (b < c)
  {
    c *= 2;
    i++;
  }
  if (i <= k)
    printf("Yes");
  else
    printf("No");
  return (0);
  
  
}