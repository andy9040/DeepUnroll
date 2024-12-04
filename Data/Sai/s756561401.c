#include <stdio.h>
#include <stdlib.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int x[110],y[110],h[110];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d%d%d",x+i,y+i,h+i);
	rep(i,0,101)rep(j,0,101){
		int ans=1e9;
		rep(k,0,n){
			int d=abs(x[k]-i)+abs(y[k]-j);
			if(h[k])ans=d+h[k];
			else ans=min(ans,d);
		}
		int flag=1;
		rep(k,0,n){
			int d=abs(x[k]-i)+abs(y[k]-j);
			flag&=(h[k]==max(0,ans-d));
		}
		if(flag){
			printf("%d %d %d\n",i,j,ans);
			return 0;
		}
	}
}