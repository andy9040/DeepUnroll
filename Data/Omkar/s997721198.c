#include <stdio.h>
#include <math.h>


int main(void){
  long long n,p,count=0,ans=1;
  scanf("%lld %lld",&n,&p);

  if(n==1){
    printf("%lld\n",p);
    return 0;
  }
  for(int i=2;(long long)i*i<=p;i++){
    while(p%i==0){
      count++;
      p/=i;
    }
    if(count>=n){
      ans*=pow(i,count/n);
    }
    count=0;
  }

  printf("%lld",ans);

  return 0;
}

