#include<stdio.h>

int color[100], n, d[100], f[100], v[100][100], time;

void visit(int u){
  int i;

  color[u] = 1;
  d[u] = ++time;
  for(i=1;i<=n;i++){
   
    if(color[i] == 0&&v[u][i]==1)visit(i);
  }
  color[u]=2;
  f[u] = ++time;
}

void dfs(){
  int i;

  for(i=1;i<=n;i++){
    color[i]=0;
  }
  time=0;
  for(i=1;i<=n;i++){
    if(color[i]==0)visit(i);
  }
}

int main(){

  int i,j,k[100],u[100],l;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      v[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d %d",&u[i],&k[i]);
    for(j=1;j<=k[i];j++){
      scanf("%d",&l);
      v[i][l] = 1;
    }}
    dfs();
    
    for(i=1;i<=n;i++){
      printf("%d %d %d\n",u[i],d[i],f[i]);
  }
    return 0;
}