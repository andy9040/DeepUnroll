#include<stdio.h>
int main(void){
    int x , y, z, ans = 0;
    scanf("%d %d %d", &x, &y, &z);
    x -= z;
    while ( 1 ) {
        x -= (y + z);
        if ( x < 0)break;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}