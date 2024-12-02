#include<stdio.h>
int main(){
  int n,t[100],a,c,i,j,b,m;
  while(1){
    scanf("%d",&n);
    if(!n)break;
    int h[201]={0};
    for(i=0;i<n;i++){
      scanf("%d",&t[i]);
      for(j=i;j;j--){
	h[t[i]]=1;
	if(t[j-1]>t[j]){
	  m=t[j-1];
	  t[j-1]=t[j];
	  t[j]=m;
	}
      }
    }
    b=0;
    i=0;
    j=1;
    a=c=n;
    while(a&&c){
      for(;i<n;i++)if(b<t[i])break;
      if(i==n){
	b=0;
	i=0;
	j=1;
      }
      else{
	b=t[i];
	a--;
	t[i]=0;//printf("t%d\n",b);
      }
      if(!(a&&c))break;
      for(;j<2*n+1;j++)if(h[j]==0&&b<j)break;
      if(j==2*n+1){
	b=0;
	i=0;
	j=1;
      }
      else{
	c--;
	b=j;
	h[j]=1;//printf("h%d\n",b);
      }    
    }
    printf("%d\n%d\n",c,a);
  }
  return 0;
}
    
      