#include <stdio.h>
int dp[101][10001];
int max(int a,int b){
  if(a<b)return b;
  else return a;
}
int main(){
  int i,j;
  int N,W;
  int w[1001];
  int v[1001];
  scanf("%d %d",&N,&W);
  for(i=1;i<=N;i++)scanf("%d %d",&w[i],&v[i]);
  for(i=0;i<=W;i++)dp[0][i]=0;
  for(i=1;i<=N;i++){
    for(j=0;j<=W;j++){
      if(w[i]>j)dp[i][j]=dp[i-1][j];
      else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
    }
  }
  printf("%d\n",dp[N][W]);
  return 0;
}