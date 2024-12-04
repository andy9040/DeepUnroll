#include <stdio.h>
#include <math.h>
int main(void){    
    int n,i;    
    double avg,dev,sum=0.0,sum2=0.0,date[100];    
    while(scanf("%d\n",&n),n>0){        
        for(i=0;i<n;i++){           
            scanf("%lf",&date[i]);           
            sum+=date[i];           
            sum2+=date[i]*date[i];        
        }        
        avg=sum/n;        
        dev=sqrt(sum2/n-avg*avg);        
        printf("%.8f\n",dev);    
    }    
    return 0;
    
}
