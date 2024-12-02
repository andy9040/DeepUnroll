#include<stdio.h>

void gyoretu(int *a, int *b, int n){
    a[0] = b[0];
    int i;

    for(i = 1; b[i]; i++){
        if(b[i - 1] < b[i]){
            a[i] = b[i - 1];
        }
        else{
            a[i] = b[i];
        }
    }
    a[n - 1] = b[n - 2];
}

int suma(int *a, int n){
    int tmp = 0;
    int i;

    for(i = 0; i < n; i++){
        tmp += a[i];
    }

    return tmp;
}

int main(void){
    int n;
    int a[100] = {0};
    int b[100] = {0};
    int i;

    scanf("%d", &n);
    for(i = 0; i < n - 1; i++){
        scanf("%d", &b[i]);
    }

    gyoretu(a, b, n);

    printf("%d", suma(a, n));
}