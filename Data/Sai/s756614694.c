#include<stdio.h>
#include<math.h>
int main(){
  double x[2],y[2];
  scanf("%lf %lf %lf %lf",&x[0],&x[1],&y[0],&y[1]);
  printf("%f\n",hypot(x[0]-y[0],x[1]-y[1]));
  return(0);
}