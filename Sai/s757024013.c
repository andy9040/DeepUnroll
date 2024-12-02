#include <stdio.h>
int main(){
  int a,b,c=1;
  char s[20];
  scanf("%d%d%s",&a,&b,s);
  for(int i=0,i<a;i++)if(!('0'<=s[i]&&s[i]<='9'))c=0;
  if(!(s[a]=='-'))c=0;
  for(int i=a+1,i<a+b+1;i++)if(!('0'<=s[i]&&s[i]<='9'))c=0;
  puts(c?"Yes":"No");
}