#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int key;
    struct node *prev, *next;
}Node;

  Node *nil;

void init(){ // ???????????????
    nil = (Node*)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void insert(int key){  
    Node *x = (Node*)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

Node* Search(int key){
    Node* x = nil->next;
    while(x != nil && x->key != key){
        x = x->next;
    }
    return x;
}

void deleteNode(Node *t){
    if(t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void deleteKey(int key){
    deleteNode(Search(key));
}

void print(){
    Node* x = nil->next;
    int i = 0;
    while(1){
        if(x == nil) break;
        if(i++ > 0) printf(" ");
        printf("%d", x->key);
        x = x->next;
    }
    printf("\n");
}

int main(void){
    int n,key,i,size = 0;
    char com[20];
    scanf("%d",&n);
    init();
    for(i=0;i<n;i++){
        scanf("%s %d", com, &key);
        if(com[0] == 'i'){
            insert(key);
        }else if(com[0] == 'd'){
            deleteKey(key);
        }
    }
    print();
    return 0;
}