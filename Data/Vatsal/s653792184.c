#include <stdio.h>

int main(void)
{
  int x1, x2, x3, x4, y1, y2, y3, y4;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  
  if (x2 >= x1 && y2 >= y1) {
    x3 = x2-y2+y1;
    y3 = y2+x2-x1;
    x4 = x3-x2+x1;
    y4 = y3-y2+y1;
  }
  else if (x2 >= x1 && y2 < y1) {
    x3 = x2-y2+y1;
    y3 = y2-x1+x2;
    x4 = x3-x2+x1;
    y4 = y3-y2+y1;
  }
  else if (x2 < x1 && y2 < y1) {
    x3 = x2-y1+y2;
    y3 = y2+x2-x1;
    x4 = x3-x2+x1;
    y4 = y3-y2+y1;
  }
  else {
    x3 = x2-y2+y1;
    y3 = y2+x2-x1;
    x4 = x3-x2+x1;
    y4 = y3-y2+y1;
  }
  printf("%d %d %d %d\n", x3, y3, x4, y4);
}
