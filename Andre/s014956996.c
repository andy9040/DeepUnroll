#include<stdio.h>

#define P 5

int main(void)
{

        int card[P] = {0, 0, 0, 0, 0};
        int i = 0, j= 0, m = 0;
        int count = 0;
        int t = 0;
        int c[P] = {0, 0, 0, 0, 0};

        while(scanf("%d,%ad,%d,%d,%d", &card[0], &card[1], &card[2], &card[3], &card[4]) != EOF)
        {
                for(i = 0; i < P ; i++)
                {
                        for(j = 0; j < P ; j++)
                        {
                                if(card[i] > card[j])
                                {
                                        m = card[i];
                                        card[i] = card[j];
                                        card[j] = m;
                                }
                        }
                }
                /*
                for(i = 0 ;i < P; i++)
                {
                        printf("%d\n",card[i]);
                }*/

                for(i = 0; i < P ; i++)
                {
                        for(j = i + 1; j < P ; j++)
                        {
                                if(card[i] == card[j])
                                {
                                        count++;
                                }
                        }
                }
/*----------------------------------------------------------*/
                if(count == 0)
                {
                        for(i = 0 ;i < P; i++)
                        {
                                c[i] = card[i] + i;
                        }
                        for(i = 1 ;i < P; i++)
                        {
                                if(c[0] == c[i])
                                {
                                        t++;
                                }
                        }
                        if(t == 4||
                        (card[0] == 13 && card[1] == 12 && card[2] == 11 && card[3] == 10 && card[4] == 1))
                        {
                                printf("straight\n");
                        }
                        else
                        {
                                printf("null\n");
                        }
                }
                else if(count == 1)
                {
                        printf("one pair\n");
                }
                else if(count == 2)
                {
                        printf("two paor\n");
                }
                else if(count == 3)
                {
                        printf("three card\n");
                }
                else if(count == 4)
                {
                        printf("full house\n");
                }
                else if(count == 6)
                {
                        printf("four card\n");
                }
                t = 0;
                count = 0;

        }
        return 0;
}