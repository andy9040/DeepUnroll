#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
int a,b,c;
scanf("%d %d %d",&a,&b,&c);
if((c>a&&c>b)||(c<a&&c<b)){printf("No");}
else{printf("Yes");}
return 0;
}
