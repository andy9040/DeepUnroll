#include<stdio.h>
int main(){
	int n,a[105],t,i,p,q,x,ans;
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		scanf("%d",&t);
		p=0,q=n-1;ans=0;
		while(1){
			x=(p+q)/2;
			ans++;
			if(t==a[x] || p>=q)break;
			if(t>a[x])p=x+1;
			else q=x-1;
			//printf("%d %d\n",p,q);
			//if(t==a[x] || p==q)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}