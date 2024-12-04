#include <stdio.h>
int main(void){
    int i,t,n,s;
    
    for(i=0;i<4;i++){
        scanf("%d %d",&t,&n);
        switch(t){
            case 1 :s=6000*n;break;
            case 2 :s=4000*n;break;
            case 3 :s=3000*n;break;
            case 4 :s=2000*n;break;
        }
        printf("%d\n",s);
    }
    return 0;
}