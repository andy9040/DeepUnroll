#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}

int main(void){
    int N;

    scanf("%d",&N);

    int n=N/3;
    int na=N%3;

    if(na!=0){
        printf("No\n");
        return 0;
    }

    int a[N];
    int i;
    
    for(i=0;i<N;i++){
        scanf("%ld",&a[i]); 
    }

    qsort(a,sizeof(a)/sizeof(int),sizeof(int),compare_int);

    int s=a[0];
    int t=a[n];
    int l=a[N-1];
    int sa=t^l;

    if(s!=sa){
        printf("No\n");
        return 0;
    }

    if(a[0]==0&&a[n-1]==0&&a[n]==a[N-1]){
        printf("Yes\n");
    }else if(a[0]!=0&&a[0]==a[n-1]&&a[n]==a[2*n-1]&&a[2*n]==a[3*n-1]&&a[n-1]!=a[n]&&a[n]!=a[N-1]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
   
    return 0;
}