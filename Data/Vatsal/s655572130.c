#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a==b&&a+2==c&&b+2==c)
    printf("YES");
    else
    printf("NO");
}