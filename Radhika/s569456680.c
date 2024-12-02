#include<stdio.h>
#include<math.h>
int main(void){
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  printf("%.8lf\n",sqrt((c-a)*(c-a)+(d-b)*(d-b)));
  return 0;
}