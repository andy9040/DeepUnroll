#include <stdio.h>

#define MAX_N 100000
int tmpa[MAX_N],tmpb[MAX_N];

void func(int Len,long long *heada){
    int cent = Len/2;
    int tip  = Len%2;
    if(Len > 2){
        func(cent, heada);
        func(cent+tip, heada+cent);
    }
    int i,j,k;
    i = k = 0;
    j = cent;
    if(Len == 1){
        tmpa[k] = heada[0];
        k++;
    }else{
        while(i < cent && j < Len){
            if(heada[i] > heada[j]){
                tmpa[k] = heada[i];
                k++;
                i++;
            }else{
                tmpa[k] = heada[j];
                k++;
                j++;
            }
        }

        while(i < cent){
            tmpa[k] = heada[i];
            k++;
            i++;
        }

        while(j < Len){
            tmpa[k] = heada[j];
            k++;
            j++;
        }
    }
    int l;
    for(l = 0;l < k;l++){
        heada[l] = tmpa[l];
    }
    return;
}

int main(void){
    int N;
    int A[MAX_N],B[MAX_N];
    long long AB[MAX_N];
    scanf(" %d",&N);
    int i;
    for(i = 0;i < N;i++){
        scanf(" %d %d",&A[i],&B[i]);
        AB[i] = A[i] + B[i];
    }
    func(N,AB);
    int bsum = 0;
    for(i = 0;i < N;i++){
        bsum += B[i];
    }
    long long ans = 0;
    for(i = 0;i < N;i+=2){
            ans += AB[i];
    }
    ans -= bsum;
    printf("%d\n",ans);
    return 0;
}