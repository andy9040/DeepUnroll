#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
   unsigned int ar[n];
   int i;
   for(i=0;i<n;i++)
   {
       scanf("%d",&ar[i]);
   }
    int c=1;
    for(i=0;i<n;i++)
    {
        if(ar[i]%2==0)
        {
            if((ar[i]%5==0)||(ar[i]%3==0))
            {
                c=1;
            }
            else
                c=0;

        }
    }
    if(c==1)
        printf("APPROVED");
    else
        printf("DENIED");
    return 0;


}
