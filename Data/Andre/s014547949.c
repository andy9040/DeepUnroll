#include<stdio.h>
#include<math.h>

int main(void){
  int n,i;
  float xa,ya,ra,xb,yb,rb;
  float d,a;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%f %f %f %f %f %f",&xa,&ya,&ra,&xb,&yb,&rb);

    a = pow((xb-xa),2)+pow((yb-ya),2);
    d = sqrt(a);

    if( ra + rb < d )
      printf("0\n");
    else if( fabs( ra - rb ) <= d)
      printf("1\n");
    else if( ra - rb > d)
      printf("2\n");
    else
      printf("-2\n");

  }

  return 0;
}