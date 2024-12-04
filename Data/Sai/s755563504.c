#include <stdio.h>

main(){
    int N,K;
    scanf("%d", &N);
    scanf("%d", &K);
    int i, s=1;
    for(i=1; i<=N; i++){
        if(s*2<s+K){
            s*=2;
        }
        else{
            s=s+K;
       }
    }
    printf("%d", s);
}
