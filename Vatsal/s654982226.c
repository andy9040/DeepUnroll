
#include <stdio.h>

int main()
{
long long int n,sum=0,i;
char a[100000];
gets(a);

if(atoi(a)%2==0)
{
    printf("%lld",strlen(a)/2+1);
}
else{
    printf("%lld",strlen(a));
}
    return 0;
}
