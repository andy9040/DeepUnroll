#include <stdio.h>

unsigned int c(unsigned int num) {
    unsigned int i;
    unsigned int count = 0;
    for( i=1; i<=num; ++i ){
        if( num%i == 0 ) count++;
    }
    return count;
}

int main(void)
{
    unsigned int n, ans;
    scanf("%u", &n);

    for(int i = 1; i <= n; i++) {
        ans = i * c(i);
    }
    printf("%u", ans);
    return 0;
}
