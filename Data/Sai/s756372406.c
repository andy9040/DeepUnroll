#include<stdio.h>
int main(){
char c;
  int s,s2;
  scanf("%c",&c);
  for(int i=0;i<10;i++){
    int j=i;
  while(c[j]=='A'||c[j]=='T'||c[j]=='C'||c[j]=='G'){
  s++;j++;
  }
    if(s2<s)s2=s;
  }
  printf("%d\n",s2);
}