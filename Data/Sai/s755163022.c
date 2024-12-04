#include <stdio.h>
int main(void){
    int N;
    scanf("%d",&N);
    int m = N/1000;
    if(N%1000 == 0){m = 1000*m;}
    m = 1000*(m+1);
    int ans = m - N;
    printf("%d",ans);
    return 0;
}