/*abc157D*/
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long com(int x, int y);
long long gya(long long tmp);

int main(void) {
  int a, b, i, max=1;
  long long n, n2, spe=1, x[31], p=2;
  //spe:種類, x:2^(i^2),p:2^i
  scanf(" %lld %d %d", &n, &a, &b);

  x[0]=1, x[1]=2, n2=n;
  for(i=2; n >= p; i++){
    p*=2;
    x[i]=x[i - 1] * x[i - 1] % (1000000007);
    max=i;
  }

  for(i=max; i >= 0; i--){
    if(n2 >= pow(2, i - 1)){
      n2-=pow(2, i - 1);
      spe=spe * x[i] % (1000000007);
    }
  }

  spe-=com(n, a) + com(n, b) + 1;
  if(spe <= 0) spe=spe % 1000000007 + 1000000007;
  printf("%lld", spe);

}
long long com(int x, int y) {
  int i;
  long long ret=1, tmp=1;

  for(i=0; i < y; i++){
    ret=ret * (x - i) % 1000000007;
    tmp=tmp * (i + 1) % 1000000007;
  }
  return (ret * gya(tmp)) % 1000000007;
}

long long gya(long long a) { //逆元を求める
  long long m=1000000007, b=m, u=1, v=0, c, t;
  while(b){
    t=a / b; //何これ
    a-=t * b, u-=t * v; //何これ
    c=a, a=b, b=c, c=u, u=v, v=c; //swap
  }
  return (u + m) % m;
}
