#include<stdio.h>
int main()
{
    char p[2];
    {
        scanf("%s",&p);
        p[0]++;
        printf("%s\n",p);
    }
}
