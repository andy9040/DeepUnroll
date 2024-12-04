#include<stdio.h>
#include<stdlib.h>
int asc(const void *a,const void *b){return *(long long *)b-*(long long*)a;}
#define ll long long
int main(){
    ll x,y,a,b,c,i;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&a,&b,&c);
    ll p[a],q[b],r[c];
    for(i=0;i<a;i++) scanf("%lld",&p[i]);
    for(i=0;i<b;i++) scanf("%lld",&q[i]);
    for(i=0;i<c;i++) scanf("%lld",&r[i]);
    qsort(p,a,sizeof(long long),asc);
    qsort(q,b,sizeof(long long),asc);
    qsort(r,c,sizeof(long long),asc);
    ll max=r[0];
    ll ans=0;
    ll countp=0,countq=0;
    for(i=0;countp<x&&p[i]>=max&&i<a;i++){
        ans+=p[i];
        countp++;
    }
    for(i=0;countq<y&&q[i]>=max&&i<b;i++){
        ans+=q[i];
        countq++;
    }
    ll z=countp;
    ll countr=0;
    for(;countp<x;countp++){
        if(max>p[z]&&countr<c){
            ans+=max;
            countr++;
            max=r[countr];
        }
        else{
            z++;
            ans+=p[z-1];
        }
    }
    z=countq;
    for(;countq<y;countq++){
        if(max>q[z]&&countr<c){
            ans+=max;
            countr++;
            max=r[countr];
        }
        else{
            ans+=q[z];
            z++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}