#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  long long n;
  double p;
  scanf("%llu %lf",&n,&p);
  int i;
  int *a;
  a = (int *)malloc(sizeof(int) * (long long)p);
  for (i=0;i<p;i++) a[i]=0;

  double t = p;

  if (p == 1) {printf("1\n"); free(a);return 0;}
  else {
    for(i=2;i<=p;){
      double aa = p/i;
      if (aa == (long long) aa) {
        if (aa == 1) {a[i]+=1; break;}
        else {a[i]+=1; p=aa;}
      } else i++;
    }
  }
  int ans = 1;
  for (i=2; i<=t; i++) {
    int d = a[i] / n;
    if (d >=1)  ans *= pow(i,d);
  }

  printf("%d\n", ans);
  free(a);
  return 0;
}
