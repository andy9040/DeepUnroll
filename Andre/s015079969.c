#include<stdio.h>
#include<math.h>

int main(void)
{
int x=0,n,i;
int a[21];

scanf("%d",&n);

for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}

for(i=2;i<n;i++)
{
if(a[i-1]>a[i]&&a[i+1]<a[i])
{
x=x+1;
}
if(a[i+1]>a[i]&&a[i-1]<a[i])
{
x=x+1;
}
}

printf("%d",x);

return 0;
}
