#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

char s[3010],t[3010];
ll sn,tn;
ll dp[3010][3010];
int main(){
	scanf("%s %s",s,t);
	sn=strlen(s);
	tn=strlen(t);
	rep(i,0,sn+1)rep(j,0,tn+1){
		if(s[i]==t[j])dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
		dp[i+1][j  ]=max(dp[i+1][j  ],dp[i][j]);
		dp[i  ][j+1]=max(dp[i  ][j+1],dp[i][j]);
//		printf("%lld ",dp[i][j]);if(j==tn)puts("");
	}
	
	char ans[3010]="";
	int len=dp[sn][tn];
	while(len){
		if(dp[sn][tn]==dp[sn-1][tn])sn--;
		else if(dp[sn][tn]==dp[sn][tn-1])tn--;
		else{
			ans[--len]=s[sn-1];
			sn--;
			tn--;
		}
//		printf("%lld %lld\n",sn,tn);
	}
	puts(ans);
	return 0;
}