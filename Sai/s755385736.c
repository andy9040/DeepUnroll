#include<stdio.h>
int n,m,a[10],b[15],c[10];
int main()
{
    for(int i=1;i<=9;i++)
            scanf("%d",&a[i]);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=9;i++)
            if(a[i]==b[k])
            {
                c[i]++;
                break;
            }
    if(c[1]&&c[2]&&c[3]||c[4]&&c[5]&&c[6]||c[7]&&c[8]&&c[9]||c[1]&&c[5]&&c[9]||c[3]&&c[5]&&c[7]||c[1]&&c[4]&&c[7]||c[2]&&c[5]&&c[8]||c[3]&&c[6]&&c[9])
        printf("Yes");
    else
        printf("No");
    return 0;
}