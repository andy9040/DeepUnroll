#include<stdio.h>

int main()
{
    int n,i,m,sum=0,c,d=0;
    scanf("%d %d",&n,&m);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
       sum=sum+a[i];


    }
    c=(sum/(4*m));

    for(i=0;i<n;i++)
    {
        if(a[i]>=c)
            d=d+1;
    }

    if(d>m)
        printf("Yes");
    else
        printf("No");

}
