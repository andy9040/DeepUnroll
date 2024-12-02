#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int N, H, i, j;
  scanf("%d%d", &N, &H);
  int b[N];
  int tmp=0, a=0, num=0;
  
  for(i=0;i<N;i++){
    scanf("%d%d", &tmp, &b[i]);
    if(tmp>a)a=tmp;
  }
  
  for(i=0;i<N-1;i++){
    for(j=0;j<N-i-1;j++){
      if(b[j]<b[j+1]){
        tmp=b[j];b[j]=b[j+1];b[j+1]=tmp;
      }
    }
  }
  
  for(i=0;i<N;i++){
    if(b[i]<=a){
      num+=H/a+(H%a!=0);
      break;
    }else{
      num+=1;
      H-=b[i];
      if(i==N-1)num+=H/a+(H%a!=0);
    }
  }
  
  printf("%d\n", num);
  
}
