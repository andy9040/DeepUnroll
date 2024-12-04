#include <stdio.h>
int main(){
  char s[10];
  scanf("%s",s);
  
  int i=0, ans=0;
  //for(;i<3;++i) ans += s[i]-'0';
  for(;i<3;++i){
    if(s[i]=='1') ans++;
  }
  
  printf("%d\n",ans);
  return 0;
}
