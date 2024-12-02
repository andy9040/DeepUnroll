#include<stdio.h>
#include<math.h>
int count=0;
int mod_pow(int x,int n,int p){
	int ret=1;
	while(n>0){
		if(n&1){
			ret*=x;
			ret%=p;
		}
		x*=x;
		x%=p;
		n>>=1;
	}
	return ret;
}
int combination(int n, int r)
{
	if (r == 0 || r == n)
	return (1);
	else if (r == 1)
	return (n);
	return (combination(n - 1, r - 1) + combination(n - 1, r));
}
int main(){
	int n,a,b;
	scanf("%d",&n);
	scanf("%d",&a);
	scanf("%d",&b);
	int A=mod_pow(2,n,1000000007)-1;
	A-=combination(n,a);
	A-=combination(n,b);
	printf("%d",A);
}