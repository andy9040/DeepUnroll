#include <stdio.h>
 
int main(){
    int m, d;
    int  days[11] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    char day[7][9] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    while(scanf("%d %d", &m, &d), m != 0){
        while(--m > 0) d += days[m - 1];
        
        printf("%s\n", day[(d + 2) % 7]);
    }
 
    return 0;
}