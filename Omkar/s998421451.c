#include <stdio.h>
#include <string.h>
int main(void){
  char buf[100];
    fgets(buf, sizeof(buf), stdin);

   
   char k[100];
    sscanf(buf, "%s", k);
   char s[100];
    sscanf(buf, "%s", s);
  
   int kLength = strlen(k);
   int sLength = strlen(s);
  
  if(kLength>=sLength){
   printf("%s\n", s);
  }else if(kLength<sLength){
     strncpy(s, s,  7);
     printf("%s...\d",s );
  }
  }