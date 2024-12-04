#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d",&x);
    if(x%1000==0)printf("0\n");
    else {
            printf("%d\n",1000-(x%1000));
    }
    return 0;

}
