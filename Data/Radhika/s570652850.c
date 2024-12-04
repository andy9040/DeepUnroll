#include <stdio.h>
#include <string.h>
int main()
{
    char str[100000];
    int i=0,count=0,N=0,revcount=0,t=0;
    scanf("%s",&str);
    N=strlen(str);
    for(i=0;i<N-1;i++)
    {
        if(str[i]=='0' && str[i+1]!='1')
        {
            str[i+1]='1';
            count++;
        }
        if(str[i]=='1' && str[i+1]!='0')
        {
            str[i+1]='0';
            count++;
        }
    }
    strrev(str);
     for(i=0;i<N-1;i++)
    {
        if(str[i]=='0' && str[i+1]!='0')
        {
            str[i+1]='1';
            revcount++;
        }
        if(str[i]=='1' && str[i+1]!='1')
        {
            str[i+1]='0';
            revcount++;
        }
    }
    if(revcount<count)
    {
        t=revcount;
    }
    else
    {
        t=count;
    }
    printf("%d\n",t);
return 0;
}