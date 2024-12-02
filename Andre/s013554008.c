#include <stdio.h>

int main(void){
int N;
scanf("%d",&N);
printf("%d",(1000-N%1000)%1000);
}