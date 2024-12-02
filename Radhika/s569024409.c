
#include <stdio.h>
#include <math.h>

int main() {
  int n,i,j,l;
  double s[10020];
  double a2,m,a;
  
  while(1) {
    m=0;
    a2 = 0;
    scanf("%d" , &n);
    if(n == 0) {
      break;
    }

    for(i=0;i<n;i++) {
      scanf("%lf", &s[i]);
	m=m+s[i];
	//printf("m[%d] = %lf\n",i ,m);
    }
    m=m/n;

    for(i=0; i<n; i++) {
      a2 =a2+(s[i]-m)*(s[i]-m);
    }
    a2 = a2/n;

    printf("%.11lf\n",sqrt(a2));

  }

  return 0;

}
