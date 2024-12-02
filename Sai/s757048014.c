#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

int main(void){
    int input[MAX];
    int i,j;
    double x1,x2;
    
    for(i=0;i<50;i++){
        scanf("%d",&input[i]);
        if(input[i]==-1){
            break;
        }
    }

    for(j=0;j<i;j++){
        x1=(double)input[j]/2;
        x2=x1-(pow(x1,3)-input[j])/(3*pow(x1,2));
        if(fabs(pow(x2,3)-input[j])<0.00001*input[j]){
            
        }
        else{
            do{
                x1=x2;
                x2=x1-(pow(x1,3)-input[j])/(3*pow(x1,2));
            } while(fabs(pow(x2,3)-input[j])>0.00001*input[j]);
        }
        printf("%lf\n",x2);
    }
    return 0;
}
