#include <stdio.h>
int main(void){
    int N, L[101], count=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &L[i]);
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                if(L[i]!=L[j] && L[i]!=L[k] && L[j]!=L[k]) {
                    if(L[i]+L[j]>L[k] && L[j]+L[k]>L[i] && L[k]+L[i]>L[j]){
                        count++;
                    }
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}