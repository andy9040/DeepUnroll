#include<stdio.h>
int main(){
  int n,s,a;
  while(1){
    scanf("%d",&n);
    if(!n)break;
    s=0;
    for(a=5;a<20000;a*=5){
      s+=n/a;
    }
    printf("%d\n",s);
  }
  return 0;
}