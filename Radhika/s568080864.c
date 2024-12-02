#include <stdio.h>
int main(){
        int m,d,ans;
        while(1){
        scanf("%d %d",&m,&d);
        if(m == 0 && d == 0){
                break;
        }
        if(m ==1){
                ans = d;
        }else if(m == 2){
                ans = d + 31;
        }else if(m == 3){
                ans = d + 60;
        }else if(m == 4){
                ans = d + 91;
        }else if(m == 5){
                ans = d + 121;
        }else if(m == 6){
                ans = d + 152;
        }else if(m == 7){
                ans = d + 182;
        }else if(m == 8){
                ans = d + 213;
        }else if(m == 9){
                ans = d + 244;
        }else if(m == 10){
                ans = d + 274;
        }else if(m == 11){
                ans = d + 305;
        }else if(m == 12){
                ans = d + 335;
        }
        switch (ans % 7){
        case 0 :
                printf("Wednesday\n");
                break;
        case 1 :
                printf("Thursday\n");
                break;
        case 2 :
                printf("Friday\n");
                break;
        case 3 :
                printf("Saturday\n");
                break;
        case 4 :
                printf("Sunday\n");
                break;
        case 5 :
                printf("Monday\n");
                break;
        case 6 :
                printf("Tuesday\n");
                break;
        }
        }
return 0;
}