/*  ex5_2
    L40S38  */
#include<stdio.h>

int main(void){
    int tribonacci[1000000];
    int n;
    scanf("%d",&n);
    tribonacci[0]=0;
    tribonacci[1]=0;
    tribonacci[2]=1;
    if(n>3){
        for(int i=2;i<n-1;i++){
            tribonacci[i+1]=tribonacci[i]+tribonacci[i-1]+tribonacci[i-2];
        }
    }
    printf("%d\n",tribonacci[n-1]);
    return 0;
}
