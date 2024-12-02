//20:35-

#include<stdio.h>

long long gcd(long long a, long long b){
    while(1){
        if(a < b){
            b -= a;
        }
        else if(a > b){
            a -= b;
        }
        else{
            return a;
        }

        if(a==0 || b==0){
            break;
        }
    }

    return a==0?b:a;
}

#define DEBUG if(0)

int main(){
    int N;
    scanf("%d", &N);

    long long A[100001]; 
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    
    int n = N;
    /*
    for(int i=0; i<N; i++){
        if(A[i]==0)
            continue;
        for(int j=0; j<N; j++){
            if(i==j)
                continue;
            if(A[i] == A[j]){
                n--;
                A[j] = 0;
            }
        } 
    }

    while(1){
        int flag = 1;
        for(int i=1; i<N; i++){
            if(A[i-1] < A[i]){
                flag = 0;
                long long tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
            }
        }
        if(flag)
            break;
    }
    */

    long long g[100001];
    long long t = gcd(A[0], A[1]);
    g[0] = A[0];
    g[1] = t;
    for(int i=2; i<n; i++){
        if(t%A[i]!=0)
            t = gcd(t, A[i]);
        g[i] = t;
    }
    long long max = t;
    




    /*
    DEBUG{
        printf("A:");
        for(int i=0; i<N; i++){
            printf("%d ", A[i]);
        }
        printf("\n");
        printf("tobasanai max = %lld\n", max);
    }

    DEBUG{
        printf("saigo tobashi g[n-1] = %lld\n", g[n-1]);
    }

    max = max < g[n-1] ? g[n-1] : max;
    */


    for(int skip=0; skip<n; skip++){
        long long t;
        if(skip==0)
            t = A[1];
        else
            t = g[skip-1];
        DEBUG printf("skip=%d(t=%lld):  ", skip, t);
        for(int i=skip+1; skip==n-1 || i<n; i++){
            if(skip==n-1)
                t = g[n-2];
            else{
                if(t%A[i]!=0)
                    t = gcd(t, A[i]);
            }
            DEBUG printf("%lld ", t);
            if(max > t){
                DEBUG printf("dead!");
                break;
            }
            if(skip==n-1)
                break;
        }
        if(max < t){
                max = t;
                DEBUG printf("max!");
        }
        DEBUG printf("\n");
    }

    printf("%lld\n", max);

    return 0;
}