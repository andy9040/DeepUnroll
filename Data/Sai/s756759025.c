#include<stdio.h>

int main(void){
  int k,i,slen;
  char s[101];

  scanf("%d", k);
  scanf("%s", s);

  slen = strlen(s);
  for(i = 0; i <= slen && i <= k; i++){
    printf("%s", s[i]);
  }
  if(slen < k){
    printf("...\n");
  }else{
    printf("\n");
  }
}
