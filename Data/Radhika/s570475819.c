#include <stdio.h>
#include <string.h>
int main(void){

  char S[20];
  int count=0;
  int max=0;
  int len=0;
  
  scanf("%s",S);
  len=strlen(S);
  
  for(int i=0;i<len;i++){
  	 if(S[i]=='A' || S[i]=='C' || S[i]=='G' || S[i]=='T'){
  		count++;
        if(count>max){
        	max=count;
        }
     }
    count=0;
  }

  printf("%d",max);
  
 return 0;
}