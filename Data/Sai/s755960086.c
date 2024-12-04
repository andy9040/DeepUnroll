#include<stdio.h>
int main(){
  int i,j,b,c;
  char s[1010],k[]={"qwertasdfgzxcvbyuiophjklnm"};
  while(scanf("%s",s),s[0]-'#'){
    b=2;
    for(i=c=0;s[i];i++){
      for(j=0;s[i]-k[j];j++);
      if(b-j/15)c++;
      b=j/15;
    }
    printf("%d\n",c-1);
  }
  return 0;
}