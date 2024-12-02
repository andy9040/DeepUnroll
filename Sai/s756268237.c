#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int key;
    struct node *nxt, *pre;
}Node;

Node *nil;

void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->nxt = nil->nxt;
    nil->nxt->pre = x;
    nil->nxt = x;
    x->pre = nil;
}

void deleteNode(Node *t){
    if(t == nil) return;
    t->pre->nxt = t->nxt;
    t->nxt->pre = t->pre;
    free(t);
}

void delete(int key){
    Node *cur = nil->nxt;
    while(cur != nil && cur->key != key){
      cur = cur->nxt;
    }
    deleteNode(cur);
}

void deleteFirst(){
    deleteNode(nil->nxt);
}

void deleteLast(){
    deleteNode(nil->pre);
}

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->nxt = nil;
    nil->pre = nil;
}

void print(){
    Node *cur = nil->nxt;
    int m = 0;
    while(1){
        if(cur == nil) break;
        if(m++ > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->nxt;
    }
    printf("\n");
}

int main(void){
    int n, i, key;
    char cmd[20];

    scanf("%d", &n);
    init();
    for(i=0; i<n; i++){
        scanf("%s%d", cmd, &key);
        if(cmd[0] == 'i') insert(key);
        else if(cmd[0] == 'd'){
            if(strlen(cmd) > 6){
            if(cmd[6] == 'F') deleteFirst();
            else if(cmd[6] == 'L') deleteLast();
            } else {
            delete(key);
            }
        }
    }
    print();
    return 0;
}