#include<stdio.h>

int main(){

int a,b;
char s;

while(1){
scanf("%d %c %d",&a,&s,&b);
if(s=='?')break;
if(s=='+')printf("%d\n",a+b);
if(s=='-')printf("%d\n",a-b);
if(s=='*')printf("%d\n",a*b);
if(s=='/')printf("%d\n",a/b);
}
return 0;
}