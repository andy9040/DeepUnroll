#include <stdio.h>
#include <string.h>

int main(void)
{
    int a,b,c,k;
    int ans=0;

    scanf("%d %d %d %d",&a,&b,&c,&k);
    //printf("%d %d %d %d\n",a,b,c,k);

    if (a==k)
        ans=1*a;
    else if (a!=k && (k-a)==b)
        ans=1*a;
    else if (a!=k && (k-a)>b)
        ans=1*a+0*(k-a)+(-1*(k-a-b));

    printf("%d\n",ans);
    // if (strcmp(s,"ABC")==0)
    //     printf("%s\n","ARC");
    // else if (strcmp(s,"ARC")==0)
    //     printf("%s\n","ABC");

    return 0;
    

}