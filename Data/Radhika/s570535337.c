#include<stdio.h>

int main(){
    long long H, W;
    scanf("%lld %lld", &H, &W);
    printf("%lld\n", (H >> 1) * W  + (H & 1) * ((W + 1) >> 1));
    return 0;
}