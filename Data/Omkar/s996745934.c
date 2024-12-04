#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[]) {
    int i,n;
    double sum=0,ave,s,sum2=0;
    double a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf",&a[i]);
        sum+=a[i];
    }
    ave=sum/n;
    for(i=0;i<n;i++){
        sum2=sum2+(a[i]-ave)*(a[i]-ave);
    }
    s=sqrt(sum2/n);
    printf("%f\n",s);
    return 0;
}