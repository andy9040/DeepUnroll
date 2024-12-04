#include<stdio.h>

#define N 100

int main(){
    int A[N];
    int n,i,flag=1;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(A[i]%2==0){
            if(A[i]%3!=0 && A[i]%5!=0){
                flag = 0;
                break;
            }
        }
    }

    if(flag){
        puts("APPROVED");
    }else{
        puts("DENIED");
    }

    return 0;
}