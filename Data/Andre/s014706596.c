#include<stdio.h>
#include<stdlib.h>
int main(){
  int a,b;
  scanf("%d %d",&a,&b);
	char *num;
  num=malloc(sizeof(char)*(a+b+1));
  scanf("%s",num);
  int j;
  for(j=0;j<a;j++){
    if(num[j]>'9'||num[j]<'0'){
      printf("No");
      return 0;
    }
  }
  if(num[a]!='-'){
      printf("No");
      return 0;
  }
  for(j=a+1;j<b;j++){
    if(num[j]>'9'||num[j]<'0'){
      printf("No");
      return 0;
    }
  }
  printf("Yes");
  return 0;
}