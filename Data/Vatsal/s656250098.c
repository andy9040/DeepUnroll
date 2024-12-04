#include <stdio.h>

int main(void){
    int i, j, k,a;
    int dot;
    int point[4][2];
    for(a = 0; a < 50; a++){
    for(i = 0; i < 8; i++){
        scanf("%d", &dot);
        for(j = 7; j >= 0; j--){
            if(dot ^ (1 < j) == 0){
                point[k][0] = i;
                point[k][1] = j;
                k++;
            }
        }
    }
    if(point[0][1] + 1 == point[1][1] && point[0][1] + 2 == point[2][1]){
        puts("C");
    }else if(point[0][0] + 1 == point[1][0] && point[0][0] + 2 == point[2][0]){
        puts("B");
    }else if(point[0][1] + 1 == point[1][1] && point[1][0] + 1 == point[3][0]){
        if(point[3][1] + 1 == point[2][1])
            puts("E");
        else
            puts("A");
    }else if(point[0][1] + 1 == point[1][1] && point[0][0] + 1 == point[3][0]){
            puts("G");
    }else if(point[1][0] + 1 == point[2][0]){
        if(point[3][1] == point[1][1])
            puts("D");
        else
            puts("F");
    }
    k = 0;
    }
}
           