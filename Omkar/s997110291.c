#include <stdio.h>
#include <string.h>
#define N 1001
int main(){
  char T[N],P[N];
  int i,j,n,m,flag;
  
  scanf("%s",T);
  scanf("%s",P);
  
  n=strlen(T);
  m=strlen(P);
  
  for(i=0;i<n;i++){
    flag=0;
    for(j=0;j<m;j++){
      if(T[i+j]==P[j]) flag++;
  
    }
    if(flag==m) printf("%d\n",i);
  }

  return 0;
}