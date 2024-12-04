#include<stdio.h>
int main(){
    int m, n;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i = 0; i < n; i++) 
        scanf("%d",&a[i]);
    int sum = 0;
    for(int i = 0; i < n; i++) 
        sum += a[i];
    int count = 0;
    for(int i = 0; i < n; i++) {
        int p = a[i] * 4 * m;
        if(p >= sum)
            count++;
    }
    if(count >= m)
        puts("Yes");
    else
        puts("No");
    return 0;
}