#include <stdio.h>
#include <string.h>

typedef struct {
    char name[33];
    int weekday;
    int start;
    int time;
    int end_time;
    int flag;
} ANIME;

ANIME anime[500];
int n;
int p;

void check(int start);
void check2(int start);

int main(void)
{
    int i, j, k;
    char name[33];
    int weekday, start;
    int time;
    int s;
    int last;
    
    while (1){
        scanf("%d", &n);
        if (n == 0){
             break;
        }
        
        for (i = 0; i < n; i++){
            scanf("%s%d%d", name, &weekday, &start);
            time = weekday * 10000 + (start / 100 * 60) + (start % 100);

            for (j = 0; j < i; j++){
                if (time < anime[j].time){
                    break;
                }
            }
            
            for (k = i - 1; k >= j; k--){
                anime[k + 1] = anime[k];
            }
            
            strcpy(anime[j].name, name);
            anime[j].weekday = weekday;
            anime[j].start = start;
            anime[j].time = time;
            anime[j].end_time = time + 29;
            anime[j].flag = 0;
        }

        scanf("%d", &p);
        for (i = 0; i < p; i++){
            scanf("%s", name);
            for (j = 0; j < n; j++){
                if (strcmp(anime[j].name, name) == 0){
                    anime[j].flag = 1;
                }
            }
        }

        for (i = 0; i < n; i++){
            if (anime[i].flag != 0){
                check(i);
                last = i;
            }
        }

        check2(last);
        
        s = 0;
        for (i = 0; i < n; i++){
            if (anime[i].flag != 0){
                s++;
            }
        }
      
        printf("%d\n", s);
        
//      for (i = 0; i < n; i++){
//            printf("[%d(%s)%d-%d]\n", anime[i].flag, anime[i].name, anime[i].weekday, anime[i].start);
//        }
    }
    
    return (0);
}

void check(int start)
{
    int i;
    int start_time;
    int change;
    
    
    start_time = anime[start].time;
    
    change = -1;
    i = start - 1;
    while (i >= 0 && anime[i].flag == 0){
        if (anime[i].end_time < start_time){
            anime[i].flag = 1;
            start_time = anime[i].time;
            change = i;
        }
        i--;
    }
    if (i > 0 && change != -1 && anime[i].flag != 0){
        if (anime[i].end_time > anime[change].time){
            anime[change].flag = 0;
        }
    }
}

void check2(int start)
{
    int i;
    int end_time;
    
    end_time = anime[start].end_time;
    
    for (i = start + 1; i < n; i++){
        if (anime[i].time > end_time){
            anime[i].flag = 1;
            end_time = anime[i].end_time;
        }
    }
}