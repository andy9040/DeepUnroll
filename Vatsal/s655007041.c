#include<stdio.h>
#include<string.h>
main(){
  char str[10000];
  int i,l,j,sum;
  while(1){
    fgets(str,9999,stdin);
    l=strlen(str);
    str[l-1]='\0';
    if(strcmp(str,"END OF INPUT")==0)return 0;

    for(i=0,j=0;i<l;i++){
      if(str[i]==' '||i==l-1){
	printf("%d",j);
	j=0;
      }else{
	j++;
      }
    }
    puts("");
  }
  return 0;
}