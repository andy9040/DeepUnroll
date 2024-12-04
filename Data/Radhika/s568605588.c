#include<stdio.h>
#include<string.h>
 
int main(void){
   int x,y,i;
   char s[101];
 
   scanf("%d",&x);
   scanf("%s",s);
   
   y=strlen(s);
  
   if(y<=x){
      printf("%s\n",s);
   }else{
      for(i=0;i<x;i++){
         printf("%c",s[i]);
      }
      
      printf("...\n");
      }
   }
   return 0;
}
