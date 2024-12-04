#include <stdio.h>
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)
int main(int argc, const char *argv[])
{
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  printf("%d\n", min(n*a, b));
  return 0;
}