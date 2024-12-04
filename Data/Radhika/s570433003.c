#include<stdio.h>
#include<math.h>
int main (){
    int X[10][10], i, j, N, D, H[10], k, cout = 0;
    double sum;
    scanf("%d %d", &N, &D);
    for(i = 0; i < N; ++i){
        for(j = 0; j < D; ++j){
            scanf("%d", &X[i][j]);
        }
    }
    for(i = 0; i < N - 1; ++i){
        for(j = i + 1; j < N; ++j){
            sum = 0.0;
            for(k = 0; k < D; ++k){
                 H[k] = X[i][k] - X[j][k];
                 sum += pow((double)H[k], 2.0);
                //  printf("1 : %f\n", sum);
            }
            k = (int)sum;
            // printf("k : %d\n", k);
            k = (int)sqrt(sum);
            sum = sqrt(sum) - (double)k;
            // printf("%d %d sum : %f\n\n", i + 1, j + 1, sum);
            if(sum >= 0.0) ++cout;
        }
    }
    printf("%d\n", cout);
    return 0;
}