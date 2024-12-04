#include <stdio.h>
#include <math.h>

int main(){

int i;
double a[6];
double x,y;

while(scanf("%lf",&a[0])!=EOF){

for(i=1;i<6;i++)scanf("%lf",&a[i]);

x = (a[4]*a[2]-a[5]*a[1])/(a[4]*a[0]-a[3]*a[1]);

if(x==0) x=abs(x);

y = (a[3]*a[2]-a[5]*a[0])/(a[3]*a[1]-a[4]*a[0]);

if(y==0) y=abs(y);

printf("%.3f %.3f\n",x,y);

}

return 0;
}