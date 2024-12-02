#include <stdio.h>

int main(){
  int a = 0;
  int i;
  char moji[3];
  if(scanf("%s",moji)==1){
  	for(i=0;i< sizeof(moji);i++){
    	if(moji[i] == '1')a++;
 	 }
  }
  
  
  return 0;
}
