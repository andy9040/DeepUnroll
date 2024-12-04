#include<stdio.h>
int main(void){
    int N,M,A_N,loop;
    int max=0;
    int min=0;
    int sum=0;
    double bet;
    scanf("%d %d",&N,&M);
    for(loop=0;loop<N;loop++){
        scanf("%d",&A_N);
        if(A_N>max) max=A_N;
        if(A_N<min) min=A_N;
        sum=sum+A_N;
    }
    bet=sum*(1/(4*M));
    if(max<bet && min<bet){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}