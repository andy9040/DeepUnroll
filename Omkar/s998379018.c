#include <stdio.h>

int main(){
int i,a;
while(1){
scanf("%d",a);
if(a==0){
break;
}
i++;
printf("Case %d: %d",i,a);
}
return 0;
}