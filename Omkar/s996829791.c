#include <stdio.h>
#include <string.h>

int main(){
 int K;
 char S;
 int n;
 char m;
 char l
  
 scanf("%d", &K);
 scanf("%c", &S);
  
 n = strlen(S);
   
 if(K >= n){
  printf("S¥n");
 }else{
  l = strncpy(m, S, 7);
  strcat(l, "...");
  printf(l);
 }
  
  return 0;
}