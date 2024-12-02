#include<stdio.h>
#include<stdlib.h>

int solve(int *A, int n, int i, int m){
    if(m == 0){
        return 1;
    }
    if(i >= n){
        return 0;
    }
    return solve(A, n, i + 1, m) || solve(A, n, i + 1, m - A[i]);
}

int main(){
    int n, q, m, i;
    int *A;
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &m);
        if (solve(A, n, 0, m)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    free(A);
    return 0;
}
