#include<stdio.h>

int main(){
int a=0,b=0,i=0,c;
for(i=0;i<3;i++){
scanf("%d ",&c);
if(c==5)a++;
if(c==7)b++;
}
if(a==2&&b==1)puts("YES");
else puts("NO");
return 0;
}