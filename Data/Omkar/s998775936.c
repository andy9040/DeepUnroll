#include<stdio.h>
int main()
{
    int S,W;
    scanf("%d %d",&S,&W);
    if(S>=1&&S<=100&W>=1&&W<=100)
    {
        if(S<=W)
        {
            printf("unsafe");
        }
        else
        {
            printf("safe");
        }
    }
}
