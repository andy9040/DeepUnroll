#include<stdio.h>

int main()
{
  int i,j,h,w;

  for(;;)
    {
      scanf("%d%d", &h, &w);
      if(h == 0 && w == 0)
	{
	  break;
	}
      for(j = 0; j < h; j++)
	{
	  for(i = 0; i < w; i++)
	    {
	      if(i == 0 || j == 0 || i == (w - 1) || j == (h - 1)) /*良い*/
		{
		  printf("#");
		}
	      else
		{
		  printf(".");
		}
	    }
	  printf("\n");
	}
      printf("\n");
    }


  return 0;
}