#include <stdio.h>
#include <math.h>

int main(void){
    int n ;
    int sco[1001] ;
    int i ;
    double s , m , t , x , ans ;
    
    while(1){
        
        scanf("%d" , &n) ;
        if(n == 0){break ;}
        for(i = 0 ; i < n ; i++){
            scanf("%d" , &sco[i]) ;
        }
        
        
        s = 0 ;
        m = 0 ;
        for(i = 0 ; i < n ; i++){
            s += sco[i] ;
        }
        m = s / n ;
    
    
    
    t = 0 ;
    for(i = 0 ; i < n ; i++){
        x = sco[i] - m ;
        x = pow(x , 2) ;
        t += x ;
    }
    ans = t / n ;
    ans = sqrt(ans) ;
    
    printf("%f\n" , ans) ;
    
    }
    return 0 ;
}
