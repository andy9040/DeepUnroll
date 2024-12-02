#include<stdio.h>
void main()
{
    int c5=0,c7=0,i,arr[3];

    scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
    for(i=1;i<=3;i=i+1){
        if(arr[i-1]==5){
            c5=c5+1;
        }
        if(arr[i-1]==7){
            c7=c7+1;
        }
    }
    if(c5==2&&c7==1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
