#include <stdio.h>

int main() {
    int A,B,C,K,sum;
    
    scanf("%d %d %d %d",&A,&B,&C,&K);
    
    if (K <= A){
        sum = K;
    }else if(K > A && K <= A + B){
        sum = A;
    }else{
        sum = A - (K - A - B);
    }
    
    printf("%d\n",sum);
    
    return 0;
}
