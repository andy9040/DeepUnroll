#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MOD1 1000000007
#define MOD2 998244353
#define LIMIT1 200002
#define LIMIT2 500002
typedef long long ll;
typedef long double ld;
typedef const void cv;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define per(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define zt(a,b) (max((a),(b))-min((a),(b)))
#define absl(v) labs((v))
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll nPr(int n,int r){ll i,result=1;rep(i,r){result*=(ll)(n-i);}return result;}
ll nCr(int n,int r){ll i,result=1;if(n<r) return 0;rep(i,min(r,n-r)){result*=(ll)(n-i);result/=(ll)(i+1);}return result;}
#define nHr(n,r) nCr((int)((n)+(r)+1),(int)(r))
#define sankaku(x) (((x)*((x)+1))/2)
int dx[8]={1,0,-1,0,1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
int upint(cv *a, cv *b) { return *(int *)a < *(int *)b ? -1 : *(int *)a > *(int *)b ? 1 : 0; }
int downint(cv *a, cv *b) { return *(int *)a < *(int *)b ? 1 : *(int *)a > *(int *)b ? -1 : 0; }
int upchar(cv *left, cv *right) {return strcmp((char *)left,(char *)right);}
int downchar(cv *left, cv *right) {return strcmp((char *)right,(char *)left);}
void tmpInit(int *c,ll m) {ll i;rep(i,m) c[i]=i;}
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1){
            res *= a; if(mod>=1) res %= mod;
        }
        a *= a; if(mod>=1) a %= mod;
        n >>= 1;
    }
    return res;
}
void initialize(){
    
}
ll countDigit(ll n){
  if(n<=9) return 1;
  else return countDigit(n/10)+1;
}
int main(void){
  initialize();
  ll n,m,i,j,k,result=-1,tmp=0;
  int a[LIMIT2]={0};
  char s[LIMIT1];
  
  scanf("%lld",&n);
  for(i=1;i<=sqrtl(n);i++){
    if(n%i==0){
      tmp = max(countDigit(i),countDigit(n/i));
      //printf("%lld,%lld\n",i,tmp);
      if(result==-1) result=tmp;
      else result = min(result,tmp);
    }
  }
  printf("%lld",result);
  return 0;
}

