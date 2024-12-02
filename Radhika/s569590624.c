#include <stdio.h>

int main(void){
  int a,b;
  char s[64];
  int t = 0;
  scanf("%d%d%s",&a,&b,s);

  for(int i=0;i<a+b+1;i++){
    if(i==a){
      if((int)s[i]!= 45){
	t = 0;
	break;
      }
    }else{
      if((int)s[i]>=48&&(int)s[i]<=57){
	t = 1;
      }
    }
  }
  if(t)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
