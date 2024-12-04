#include<stdio.h>
#include<math.h>

int main(){
    int N,K;
    scanf("%d%d", &N, &K);
    
    int x,y;
    int ans=0;
    int flag=0;
   
    x = -1;
    while( flag == 0 ){
        x += 1;
        y = N / pow(K, x);
        if( y < 1 ) flag = 1;
        else ans = x+1;
    }

    printf("%d\n", ans);
    return 0;
}
