#include<stdio.h>

int main(){
    int i, j, N, M, a[100000], b[100000], k=0, h;
    scanf("%d %d", &N, &M);
    if ((M % 2) == 1) k++;
    scanf("%d %d", &a[0], &b[0]);
    for(i = 1; i < M; i++){
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] != b[i-1]) k++;
    }
    if (k != 0 || a[0] != b[i-1]){
        printf("-1\n");
        return 1;
    }
    h = M / 2 - 1;
    printf("%d %d\n", a[0], b[0]);
    printf("%d %d\n", b[M-1], a[M-1]);
    for(i = 1, j = 0; j < h; i += 2, j++){
        printf("%d %d\n", b[i], a[i]);
        printf("%d %d\n", a[i+1], b[i+1]);
    }

    return 0;
}