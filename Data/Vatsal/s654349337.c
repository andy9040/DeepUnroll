#include <stdio.h>
 
int Main(){
 int a;
 int b;
 int c;
 scanf("%d",&a);
 scanf("%d",&b);
 scanf("%d",&c);
 
 if((a==5&&b==5&&c==7)||(a==5&&b==7&&c==5)||(a==7&&b==5&&c==5)){
  printf("OK");
 } else {
  printf("NG");
 }
  return 1;
}