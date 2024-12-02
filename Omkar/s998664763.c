#include <stdio.h>
int main(){
int N,D,s,u;
scanf("%d %d",&N,&D);
u=(2*D+1);
s=(float)N/u;
if(s>(int)s)
s++;
{printf("%d",s);
}
}