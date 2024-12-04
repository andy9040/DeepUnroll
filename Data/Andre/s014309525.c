#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a, const void *b){
    //クイックソート
    return *(int*)a - *(int*)b;
}

int main(){

    int n;
    scanf("%d",&n);
    long a[n];
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }

    int zero_count=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){zero_count++;}
    }
    if(zero_count==n){
        printf("Yes\n");
        return 0;
    }

    qsort(a,n,sizeof(long),compare_int);

    long x=0;
    long y=0;
    long z=0;
    x=a[0];
    for(int i=1;i<n;i++){
        if(a[i]!=x){
            y=a[i];
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=x && a[i]!=y){
            z=a[i];
            break;
        }
    }
    
    int x_cnt=0;
    int y_cnt=0;
    int z_cnt=0;
    for(int i=0;i<n;i++){
        if(x==a[i]){x_cnt++;continue;}
        if(y==a[i]){y_cnt++;continue;}
        if(z==a[i]){z_cnt++;continue;}
    }
    if(x_cnt==y_cnt && y_cnt==z_cnt && x_cnt +y_cnt +z_cnt ==n){
        if(x==y^z && y==x^z && z==x^y){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");

    return 0;
}