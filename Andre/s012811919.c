#include<stdio.h>

int main(){
  char S[111111];
  scanf("%s",S);
  int one = 0;
  int two = 0;
  int length = 0;
  int i;
  for(i=0;i<=111111;i++)
    if(S[i] == '\0'){
      length = i;
      break;
    };
  for(i=0;i<=length/2;i++){
    if(S[2*i] == '0') one++;
    if(S[2*i+1]== '1') one++;
  };
  for(i=0;i<=length/2;i++){
   if(S[2*i] == '1') two++;
   if(S[2*i+1]== '0') two++;
  };
  if(one>=two) printf("%d\n",two);
  if(one<two) printf("%d\n",one);
}