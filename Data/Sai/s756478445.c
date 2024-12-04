#include<stdio.h>
int main(void){
  int count=0,ans=0,i;
  char S[20];
  scanf("%s",S);
  for(i=0;i<20;i++){
    if(S[i]=='A' || S[i]=='T' || S[i]=='G' || S[i]=='C'){
      count++;
      if(ans<count){
        ans=count;
      }
    }
    else{
      count=0;
    }
    if(S[i]=='\0'){
      break;
    }
  }
  printf("%d",ans);
  return 0;
}