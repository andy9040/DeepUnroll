#include<stdio.h>
int main(void){
  int k,n,i;
  char s[n];
  scanf("%d",&n);
  scanf("%s",s);
  scanf("%d",&k);
  char t[n];
  for(i==0;i<n;i++){
    if(s[i] == s[k-1]){t[i]=s[i];}
    else{t[i]='*';}
  }
  printf("%s",t);
  return 0;
}
