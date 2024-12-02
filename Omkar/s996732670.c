#include<stdio.h>
int n, s[22];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",s+i);
    int acc = 0;
    for(int i=1;i<n-1;++i)
    {
        if(s[i-1] < s[i] && s[i+1] > s[i])
            acc++;
        if(s[i-1] > s[i] && s[i+1] < s[i])
            acc++;
    }
    printf("%d\n",acc);
}
