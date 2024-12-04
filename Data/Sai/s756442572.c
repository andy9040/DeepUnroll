#include <stdio.h>

int main(){
    int M,N,i;
    int A[N],sum,count;
    scanf("%d %d",&M, &N);
    sum = 0;
    count = 0;

    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
        sum += A[i];
    }

    for(i=0;i<N;i++){
        if(1/(4*M) <= A[i]/sum){
            count +=1;
        }
    }
    if(count >=M){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
    
