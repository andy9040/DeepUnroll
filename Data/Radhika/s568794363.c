#include<stdio.h>

int main(void)
{
    int n,i,j,count,flag;

    while(scanf("%d",&n),n){
        count=0;

        for(i=n+1;i<=n*2;i++){
            flag=0;
            for(j=2;j<i;j++){
                if(i%j==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0) count++;
        }

        printf("%d\n",count);
    }
    return 0;
}