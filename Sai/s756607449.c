#include<stdio.h>

int n, G[100][100], d[100], F[100], c[100];
int t = 0;

void visit(int u){

  int i, j, v;

  c[u] = 2;
  d[u] = ++t;
  
  for(v = 1; v <= n; v++)
    if(c[v] == 0) visit(v);

  c[u] = 1;
  F[u] = ++t;
  
}

void dfs(){

  int i;

  for(i = 1; i <= n; i++){
    c[i] = 0;
    t = 0;
  }
  
  for(i = 1; i <= n; i++)
    if(c[i] == 0) visit(i);

}

int main(){
   
  int i, j, k, u, v; 

  scanf("%d", &n);
  
  for(i = 1; i <= n; i++){
    d[i] = 0;
    for(j = 1; j <= n; j++){
      G[i][j] = 0;
    }
  }
  
  for(i = 1; i <= n; i++){
    
    scanf("%d%d", &u, &k);
    
    for(j = 1; j <= k; j++){
      
      scanf("%d", &v);
      
      G[u][v] = 1;
    
    }
    
  }
  
  dfs();
  
  for(i = 1; i <= n; i++)
    printf("%d %d %d\n", i, d[i], F[i]);
  
  return 0;
  
}