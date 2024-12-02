#include<stdio.h>
#include<string.h>
int main(){
  int a = 0;
  char s[10];
  scanf("%s",s);
  if(strcmp(s,"SUN"))
    a = 7;
  else if(strcmp(s,"MON"))
    a = 6;
  else if(strcmp(s,"TUE"))
    a = 5;
  else if(strcmp(s,"WED"))
    a = 4;
  else if(strcmp(s,"THU"))
    a = 3;
  else if(strcmp(s,"FRI"))
    a = 2;
  else if(strcmp(s,"SAT"))
    a = 1;
  printf("%d",a);
  return 0;
}