#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int turn;
    char cards_t[101];
    char cards_h[101];
    
    int point_h
        ,point_t;
    int i,j;
    
    point_h =0; point_t =0;
    
    scanf("%d",&turn);
    
    for(i=0; i<=turn; i++){
        scanf("%s %s\n",&cards_t,cards_h);
        
        if(strcmp(cards_t,cards_h) < 0){
            point_h += 3;
        }else if(strcmp(cards_t,cards_h) > 0){
            point_t += 3;
        }else {
            point_h++;
            point_t++;
        }
        
        for(j=0; j<100; j++){
            cards_h[i] = 0;
            cards_t[i] = 0;
        }
    }
    printf("%d %d\n",point_t,point_h);
    
    return 0;
}