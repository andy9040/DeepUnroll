#include <stdio.h>
int main(){
    int X,x,a_num,b_num,ans;
    scanf("%d",&X);
    a_num =X/500;
    x= X % 500;
    b_num = x / 5;
    ans = a_num * 1000 + b_num *5;
    printf("%d",ans);
    return 0;
}
