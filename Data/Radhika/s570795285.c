#include <stdio.h>

int main()
{
    int a,b,c,k;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &k);
    while(b <= a){
        b *= 2;
        k--;
    }
    while(c <= b){
        c *= 2;
        k--;
    }
    if (k >= 0){
        printf("Yes");
    }
    else{
        printf("No");
    }
}