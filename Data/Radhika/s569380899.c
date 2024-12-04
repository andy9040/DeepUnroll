#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long

int main(){
  ll int h,w,ans=0;
  scanf("%lld%lld",&h,&w);
  if(h%2==0 || w%2==0){
    ans = w*h/2;
    printf("%lld",ans);
    return 0;
  }
  else{
    ans = h*w/2+1;
    printf("%lld",ans);
    return 0;
  }
}
  