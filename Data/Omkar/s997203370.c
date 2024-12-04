#include<stdio.h>
#define N 100000
int main()
{
    int count1=0,count2=0;
    char s[N];
    gets(s);
    char *p=s;
    for(;*p!='\0';p+=2)
    {
       if(*p=='0')count1++;
    }
    for(p=&s[1];*p!='\0';p+=2)
    {
        if(*p=='1')count1++;
    }
    p=s;
    for(;*p!='\0';p+=2)
    {
       if(*p=='1')count2++;
    }
    for(p=&s[1];*p!='\0';p+=2)
    {
       if(*p=='0')count2++;
    }
    if(count1<count2)
        printf("%d",count1);
    else
        printf("%d",count2);
    return 0;
}
