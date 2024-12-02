#include <stdio.h>

int main(){
  int a,b,c,k;
  scanf("%d%d%d%d",&a,&b,&c,&k);
  
  int max = 0;
  for(int i=k; i>0; i--){
    if(a>0){
      max++;
      a--;
    }else{
      if(b>0){
        b--;
      }else{
        if(c>0){
          max--;
          c--;
        }
      }
    }
  }
  printf("%d",max);
}