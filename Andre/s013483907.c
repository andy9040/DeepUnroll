#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* element;
int* next;
int* prev;
int* garbage;
int start;
int end;
int size;
int garbage_count;

void insert(int num){
    if(start == -1){
        if(garbage_count != 0){
            element[garbage[garbage_count - 1]] = num;
            next[garbage[garbage_count - 1]] = -1;
            prev[garbage[garbage_count - 1]] = -1;
            start = garbage[garbage_count - 1];
            end = garbage[garbage_count - 1];
            garbage_count--;
            size = 1;
        }else{
            element[0] = num;
            next[0] = -1;
            prev[0] = -1;
            start = 0;
            end = 0;
            size = 1;
        }
    }else{
        if(garbage_count != 0){
            element[garbage[garbage_count - 1]] = num;
            prev[start] = garbage[garbage_count - 1];
            next[garbage[garbage_count - 1]] = start;
            prev[garbage[garbage_count - 1]] = -1;
            start = garbage[garbage_count - 1];
            garbage_count--;
        }else{
            element[size] = num;
            prev[start] = size;
            next[size] = start;
            prev[size] = -1;
            start = size;
            size++;
        }
    }
}

void deleteFirst(){
    garbage[garbage_count] = start;
    garbage_count++;
    prev[next[start]] = -1;
    if(next[start] == -1){ start = -1; return; }
    start = next[start];
}

void deleteLast(){
    garbage[garbage_count] = end;
    garbage_count++;
    next[prev[end]] = -1;
    if(prev[end] == -1){ start = -1; return; }
    end = prev[end];
}

void delete(int num){
    int current = start;
    while(current != -1){
        if(element[current] == num){
            if(current == start){
                deleteFirst();
                return;
            }else if(current == end){
                deleteLast();
                return;
            }else{
                garbage[garbage_count] = current;
                garbage_count++;
                next[prev[current]] = next[current];
                prev[next[current]] = prev[current];
                if(next[current] == -1 && prev[current] == -1){ start = -1; return; }
                return;
            }
        }
        current = next[current];
    }
    return;
}

void print(){
    int i;
    int current = start;
    while(current != -1){
        printf("%d", element[current]);
        current = next[current];
        if(current != -1){ printf(" "); }
    }
    printf("\n");
    return;
}

int main(void){

    int i;
    int cmd_count;

    char* cmd;
    int num;

    element = calloc(1000000, sizeof(int));
    next = calloc(1000000, sizeof(int));
    prev = calloc(1000000, sizeof(int));
    garbage = calloc(20, sizeof(int));

    start = -1;
    garbage_count = 0;

    scanf("%d", &cmd_count);
    for(i = 0; i < cmd_count; i++){
        cmd = (char*)calloc(12, sizeof(char));
        scanf("%s", cmd);
        if(strcmp(cmd, "insert") == 0){
            scanf("%d", &num);
            insert(num);
        }else if(strcmp(cmd, "delete") == 0){
            scanf("%d", &num);
            delete(num);
        }else if(strcmp(cmd, "deleteFirst") == 0){
            deleteFirst();
        }else if(strcmp(cmd, "deleteLast") == 0){
            deleteLast();
        }
        free(cmd);
    }

    print();

    return 0;
}
