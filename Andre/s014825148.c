#include<stdio.h>

int main(void)
{
    int array[3];
    int ans = 0;
    for(int i=0;i<2;i++){
        scanf("%d", &array[i]);
    }
    ans += array[0];
    ans += array[1];
    ans += array[2];
    printf("%d", ans);
    return 0;

}