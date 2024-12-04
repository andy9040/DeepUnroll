#include<stdio.h>
#include<math.h>
#define RADIAN1 3.141592654/180.0
double area(int,int,double);
double circum(int,int,double);
double height(int,double);

int main(){
  int a,b,angle;
  double s,l,h;

  scanf("%d%d%d",&a,&b,&angle);
  printf("%.5f\n%.5f\n%.5f\n",area(a,b,RADIAN1*angle),circum(a,b,RADIAN1*angle),height(b,RADIAN1*angle));

 
  
  return 0;
}

double area(int a,int b,double angle){
  return a*b*sin(angle)/2.0;
}

double circum(int a,int b,double angle){
  return a+b+sqrt(a*a+b*b-2*a*b*cos(angle));
}
double height(int b,double angle){
  return b*sin(angle);
}