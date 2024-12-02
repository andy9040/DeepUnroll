#include<stdio.h>
int main()
{
    int a,a1=1,b,sum=0,i,c;
    scanf("%d %d",&a,&b);
    c=sqrt(a+b);
    for(i=1;i<=a;i++)
    {
        if(i<=c){
        a1=a1*2;
        //printf("%d\n",a1);
        }
        else
        a1=a1+b;
    }
    printf("%d\n",a1);
    return 0;
}
