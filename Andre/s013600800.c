#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    printf("%d", 1000-(N % 1000));
}