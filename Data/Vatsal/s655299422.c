#include <stdio.h>
int main(void) {
int A,B,C,K;
scanf("%d%d%d%d",&A,&B,&C,&K);
if(0<=A-K){
printf("%d\n",K);
}else if(0>A-K&&0<=A+B-K){
printf("%d\n",A);
}else{
printf("%d\n",A-C);
}
return 0;
}
