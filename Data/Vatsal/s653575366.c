#include<stdio.h>
#include<string.h>
int main(void){
  int n,l,i,j;
  char s[100][101],tmp[101];
  scanf("%d%d",&n,&l);
  for(i=0;i<n;i++)scanf("%s",s[i]);
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(strcmp(s[j-1],s[j])>0){
        strcpy(tmp,s[j-1]);
        strcpy(s[j-1],s[j]);
        strcpy(s[j],tmp);
      }
    }
  }
  for(i=0;i<n;i++)printf("%s",s[i]);
  return 0;
}