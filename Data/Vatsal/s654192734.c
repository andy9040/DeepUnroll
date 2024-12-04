#include<stdio.h>

int mult(int x,int y){
	if(y==0)return 0;	
	if(x%y==0)return 1;
	return -1;
}

int main(){
	int n,i,t,current,k;
	int c[500],s[500],f[500],a[500];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d",&c[i],&s[i],&f[i]);
	}
	c[i]=-1;
	s[i]=-1;
	f[i]=-1;
	
	for(i=0;i<n;i++){
		t=0;
		current=i;
		while(1){
			if(current==n-1){
				a[i]=t;
				break;
			}
			while(1){
				if(t>=s[current]){
					if(mult(t-s[current],f[current])==1){
						t+=c[current];
						current++;
						break;
					}
				}
				t++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	
	return 0;
}