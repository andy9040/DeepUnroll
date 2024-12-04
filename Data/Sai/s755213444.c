#include<stdio.h>
#include<string.h>
int main(void){
  int l,i=0,j;
  scanf("%d",&l);
  char str[l][10],tango[l][10],moji;
  scanf("%s",str[i]);
  strcpy(tango[i],str[i]);
  for(i=1;i<l;i++){
    scanf("%s",str[i]);
    strcpy(tango[i],str[i]);
    for(j=0;j<i;j++){
      if(strcmp(str[i],tango[j])==0){
        printf("No");
        return 0;
      }
    }
    for(j=0;str[i-1][j]!='\0';j++){
    }
    moji=str[i-1][j-1];
    if(moji!=str[i][0]){
      printf("No");
      return 0;
    }
  }
  printf("Yes");
  return 0;
}
  