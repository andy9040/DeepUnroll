#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n,d;
    scanf("%d%d",&n,&d);
    int X[n][d];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < d;j++){
            scanf("%d",&X[i][j]);
        }
    }
    int count = 0;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            int sum = 0;
            
                for(int k = 0;k < d;k++){
                    sum += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
                }
                double ans = sqrt((double)sum);
                if ((int)ans * (int)ans == sum){
                    count++;
                }
            
        }
    }

    printf("%d",count);
}
