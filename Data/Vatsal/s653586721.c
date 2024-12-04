#include<stdio.h>

void perfect(int n,int a[])
{
    int i;
    int tem[200]={0};

    for(i=0;i<n*2;i++){
        tem[i]=a[i];
    }

    for(i=0;i<n*2;i++){
        a[i]=tem[i/2+n*(i%2)];
    }
}

void cat(int k,int n,int a[])
{
    int i;
    int tem[200]={0};

    for(i=0;i<n*2;i++){
        tem[i]=a[i];
    }

    for(i=k;i<n*2;i++){
        a[i-k]=tem[i];
    }
    for(i=0;i<k;i++){
        a[2*n-k+i]=tem[i];
    }

}

int main()
{
    int n,m,i;
    int card[200];
    int k[1000]={0};

    scanf("%d %d",&n,&m);

    for(i=0;i<200;i++) card[i]=i+1;
    for(i=0;i<m;i++) scanf("%d",&k[i]);

    for(i=0;i<m;i++){
        if(k[i]) cat(k[i],n,card);
        else perfect(n,card);
    }

    for(i=0;i<n*2;i++) printf("%d\n",card[i]);

    return 0;
}