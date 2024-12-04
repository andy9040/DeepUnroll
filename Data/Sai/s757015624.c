#include <stdio.h>
#include <stdlib.h>

int main(){
  int x,n,k,i;
  int p[100];
  int m = scanf("%d %d\n",&x ,&n);
  for(i=1; i <= n; i++){
  	int l = scanf("%d ",&p[i]);
  }
  if (1 <= x <= 100 || 0 <= n <= 100){
    int Answer = x;
    int Answer2 = x;
	for(k=1; k <= n; k++){
      for(i=1; i <= n; i++){
        if((p[i] - x) == ( Answer - x )){
          Answer -= 1;
        }
      }
      for(i=1; i <= n; i++){
         if((p[i] - x) == ( Answer2 - x )){
           Answer2 += 1;
       	 }
       }
     }
    //printf("%d",Answer);
      if(abs( Answer - x ) > abs( Answer2 - x )){
        printf("%d",Answer2);
       }else{
        printf("%d",Answer);
       }   
  }else{
  	printf("error");
  } 
  
return 0;
}