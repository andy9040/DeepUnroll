#include<stdio.h>
#include<string.h>
int main()
{
  char c[50];
  char *p=c;
  gets(c);
  int j,sum=0;
   j=0;
int i=strlen(c);
for(j=0;j<i-1;j++)
{
  if((*(p+j)='W') && (*(p+j+1)='B'))
    {
    *(p+j)='B';
    *(p+j+1)='W';
    sum+=1;
    }
 if(*(p+j+1)=='/0')
        j=0;
}
printf("%d",sum);
return 0;
}
