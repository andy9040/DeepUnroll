#include <stdio.h>
int main()
{
    int a,b,c,d,i=1,e=0,f=1,g=0,ret;
    scanf("%d %d",&a,&b);
    ret=scanf("%d-%d",&c,&d);
    if(ret<2)
    {
        printf("No");
    }
    do
    {
        i=i*10;
        e++;
    }while(i<c);
    do
    {
        f=f*10;
        g++;
    }while(f<d);
    if(e==a&&g==b)
    {
        printf("Yes");
    }
    else
        printf("No");
    return 0;
}