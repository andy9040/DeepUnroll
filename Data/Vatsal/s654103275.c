#include<stdio.h>

int main(void){
  int a,b,c;
  int trd;
  scanf("%d %d %d",&a,&b,&c);
  if(a>b) {
    trd=a;a=b;b=trd;}
  if(a==5){
    if((b==5 && c==7) || (b==7 && c==5)) printf("YES\n");}
  else printf("NO\n");
 return 0; 
}