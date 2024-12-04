#include <stdio.h>
     
int main(void){
     
int hi,koku,suu,kokud,suud;
int n=0,m=0;
     
scanf("%d",&hi);
scanf("%d",&koku);
scanf("%d",&suu);
scanf("%d",&kokud);
scanf("%d",&suud);
printf("\n");
     
while(koku>=0){
koku-=kokud;
n++;
}
     
while(suu>=0){
suu-=suud;
m++;
}
     
if(n>=m){
hi-=n;
printf("%d\n",hi);
}
     
else if(m>n){
hi-=m;
printf("%d\n",hi);
}
     
return 0;
     
}