#include <stdio.h>
int main(void)
{
    int i,j,H,W;
    while(1)
    {
        scanf("%d%d",&H,&W);
        if(H!=0 || W!=0)
        {
            for(j=0;j<W;j++)
            {
                printf("#");
            }
            printf("\n");
            for(i=0;i<H-2;i++)
            {
                printf("#");
                for(j=0;j<W-2;j++)
                {
                    printf(".");
                }
                printf("#\n");
            }
            for(j=0;j<W;j++)
            {
                printf("#");
            }
            printf("\n");
        }
        else break;
    }
    return 0;
}