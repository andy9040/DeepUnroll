#include<stdio.h>
#include<string.h>
#define N 1000

char T[N],P[N];

int main(){
  int i,j,tlen,plen,cnt;
  scanf("%s",T);
  scanf("%s",P);
  
  tlen = strlen(T);
  plen = strlen(P);
  
 
  for(i=0;i<tlen;i++){
    cnt=0;
    for(j=0;j<plen;j++)
      if(T[i+j]==P[j]) cnt++;
    
if(cnt==plen)printf("%d\n",i);
 else i+=cnt;
  }
  
  return 0;
}