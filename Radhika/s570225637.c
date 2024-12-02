#include<stdio.h>

int main(void)
{
    int n;      //入力用
    int change = 0;
    scanf("%d",&n);

    change = 1000 - (n % 1000);
    if(change == 0)
    {
        printf("payback is %d\n",change);
    }else
    {
        change =  (1000 - (n % 1000)) % 1000;
        printf("payback is %d\n",change);
    }
   
    return 0;
}