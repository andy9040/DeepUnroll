#include<stdio.h>
#include<string.h>
#define Max(x,y) ((x>y)?x:y)
typedef struct group{
	char name[20];
	char mem[30][30];
	int n;
}group;
group x[105];
char list[2000][30];
int f,n,ff[105];
int func(int i){
	int j,k,r=0;
	if(ff[i]==1)return 0;
	else ff[i]=1;
	for(j=0;j<x[i].n;j++){
		for(k=0;k<n;k++)if(strcmp(x[k].name,x[i].mem[j])==0)break;
		if(k==n){
			for(k=0;k<f;k++)if(strcmp(x[i].mem[j],list[k])==0)break;
			if(k==f)strcpy(list[f++],x[i].mem[j]),r++;
		}else{
			r+=func(k);
		}
	}
	return r;
}
int main(){
	int i,j,k,m,g,ans;
	char s[30],t[200];
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			scanf("%s",t);
			m=strlen(t);
			memset(s,0,sizeof(s));
			f=g=0;
			for(j=0;j<m;j++){
				if('a'<=t[j] && t[j]<='z'){
					s[g++]=t[j];
				}else{
					if(f==0){
						strcpy(x[i].name,s);
						f++;g=0;
					}else{
						strcpy(x[i].mem[f-1],s);
						f++;g=0;
					}
					memset(s,0,sizeof(s));
					if(t[j]=='.')break;
				}
			}
			x[i].n=f-1;
			//printf("%s :",x[i].name);
			//for(j=0;j<x[i].n;j++)printf(" %s,",x[i].mem[j]);
			//printf("\n");
		}
		ans=0;
		f=0;
		memset(ff,0,sizeof(ff));
		//for(i=0;i<n;i++){
		//	g=func(i);
		//	ans=Max(ans,g);
			//ans+=func(i);
			//printf(" %d\n",func(i));
		//}
		//for(i=0;i<f;i++)printf("%s ",list[i]);
		printf("%d\n",func(0));
	}
	
	return 0;
}