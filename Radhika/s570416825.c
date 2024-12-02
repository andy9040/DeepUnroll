#include <stdio.h>
int main(void){
    int a, A, B;
    scanf("%d", &a);
    A = (a / 500);
    B = ((a % 500) / 5);
    printf("%ld", A * 1000 + B * 5);
    
}
