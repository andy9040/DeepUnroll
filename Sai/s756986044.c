#include<stdio.h>
int main(void)
{
    int x,n,p[101],q[102]={0},i,a,b,s;
    scanf("%d%d",&x,&n);
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    for(i=0;i<n;i++)
        q[p[i]]=1;
    a=x; b=x;
    while(1){
        if(q[a]==0){
            s=a;
            break;
        }
        else if(q[b]==0){
            s=b;
            break;
        }
        a--; b++;
    }
    printf("%d\n",s);
    return 0;
}