#include <stdio.h>

int main(){
  char s1[4],s2[4];
  scanf("%s\n%s",s1,s2);
  if(s1[0]==s2[2] && s1[1]==s2[1] && s1[2]==s2[0]) printf("YES\n");
  else printf("NO\n");
  return 0;
}