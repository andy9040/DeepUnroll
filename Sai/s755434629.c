#include<stdio.h>

int main()
{
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
if(a==5 && c==5 && b==7 || a==5 && \
b==5 && c==7 || a==7 && b==5 && c==5)
    printf("YES\n\nusising\
 three phrases of length 5,5 \
and 7,it is possible to construct\
 a Haiku.\n");
    else
    printf("NO\n");
    return 0;
}