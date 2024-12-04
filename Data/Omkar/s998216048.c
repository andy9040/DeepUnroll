#include <stdio.h>

int main(){
int a, b; 
//scanf("%d %d", &a, &b);
if(scanf("%d %d", &a, &b)==2)printf("%d\n", a+b>=24?a+b-24:a+b);
return 0;
}