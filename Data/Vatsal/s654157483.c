#include <stdio.h>
#define rep(i,l,r) for((i)=(l);(i)<(r);(i)++)
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>(0)?(a):-(a))
int main(){
    long long n,i,X,Y,H,same,j=0;
    scanf("%lld",&n);
    long long x[n],y[n],h[n];
    rep(i,0,n) scanf("%lld%lld%lld",&x[i],&y[i],&h[i]);
    rep(X,0,101){
        rep(Y,0,101){
            while(h[j]==0)j++;
            H=h[j]+abs(X-x[j])+abs(Y-y[j]);
            same=0;
            rep(i,0,n){
                if(h[i]==0||h[i]==H-abs(X-x[i])-abs(Y-y[i]))same++;
                else continue;
                if(same==n){
                    printf("%lld %lld %lld",X,Y,H);
                    return 0;
                }
            }
        }
    }
}