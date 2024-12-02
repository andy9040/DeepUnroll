#include <stdio.h>
#include <string.h>

int main(void){
  char s1[4];
  char s2[4];
  char s3[4] = {'\0'};
  scanf("%4s", s1);
  scanf("%4s", s2);
  s3[0] = s2[2];
  s3[1] = s2[1];
  s3[2] = s2[0];
  if(strcmp(s3, s1) == 0) printf("YES\n");
  else printf("NO\n");
  return 0;
}