#include <stdio.h>

int main(){
    int n,p,i,j,x,a[50];
    while(1){
        scanf("%d %d\n",&n,&p);
        if (n==0&&p==0) break;
        x=p;
        for (i=0;i<n;i++) {
        a[i]=0;
        }
        i=0;
        while (x!=1||a[i%n]!=p-1) {
            j=i%n;
            if (x==0) {
                x=a[j];
                a[j]=0;
            }
            else {
                x--;
                a[j]++;
            }
            i++;
        }
        printf("%d\n",i%n);
        
    }
    return 0;
}