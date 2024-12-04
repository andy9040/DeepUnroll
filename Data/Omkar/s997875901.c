#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,n,sum=0,m=1;
    scanf("%d",&n);
    for(j=1; j<=n; j++)
    {
        m=1;
        for(i=1; i<=sqrt(j); i++)
        {
            if(j==1)
            {
                m=1;
            }
            else if(j%i==0)
            {
                m++;
            }
         }
        sum=sum+(j*m);
    }
    printf("%d\n",sum);
    return 0;
}
