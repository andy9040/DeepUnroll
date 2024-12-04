#include<stdio.h>

int main(){
  
  int i,k,n;
  char s[1000];
  
  scanf("%d",&k);
  scanf("%s",s);
  
  for(n = 0; s[n] != '\0'; n++){
    //printf("%c",s[n]);
  }
  
  if(n <= k){
    printf("%s\n",s);
  }else{
    for(i = 0; i < k; i++){
      printf("%c",s[i]);
    }
    printf("...\n");
  }
  
  return 0;
        
}