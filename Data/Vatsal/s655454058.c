#include <stdio.h>
#include <math.h>


int main(void){
  double n;
  double s[1000];
  int i;
  double ave;
  double a;
  double sum;

  while(1) {
    ave = 0;
    a = 0;
    sum = 0;
    scanf("%lf", &n);
    if (n == 0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%lf", &s[i]);
      sum += s[i];
    }

    ave = sum / n;
  
    for(i = 0; i < n; i++) {
      a += (s[i] - ave) * (s[i] - ave);
    }

    printf("%f\n", sqrt(a / n));
  }
  
  
  return 0;
}

