#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

#define LIMIT 1000000000000
char ss[10];
int main(){
	ll s=10;
	while(s<LIMIT){
		printf("? %lld\n",s);
		fflush(0);
		scanf("%s",ss);
		if(*ss=='N')break;
		s*=10;
	}
	if(s==1000000000000){
		//答えは10べき
		s=2;
		while(s<LIMIT){
			printf("? %lld\n",s);
			fflush(0);
			scanf("%s",ss);
			if(*ss=='Y')break;
			s*=10;
		}
		printf("! %lld\n",s/2);
		fflush(0);
	}else{
		ll l=s/10+1,r=s-1;//[l,r]
		while(r-l>1){
			ll m=(l+r)/2;
			printf("? %lld0\n",m);
			fflush(0);
			scanf("%s",ss);
			if(*ss=='N')l=m+1;
			else r=m;
		}
		printf("! %lld\n",l);
		fflush(0);
	}
}