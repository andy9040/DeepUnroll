#include<stdio.h>

int main(){
  int n,i,ans=0;
  int p[21];
  scanf("%d",&n);
  for(i=0;i<n;i++){
  	scanf("%d",&p[i]);
  }
  for(int j=1;j<n-1;j++){
  	if((p[j-1]<p[j]&&p[j]<=p[j+1])||(p[j+1]<p[j]&&p[j]<=p[j-1])){
    	ans++;
    }
  }
  printf("%d",ans);
  return 0;
}

