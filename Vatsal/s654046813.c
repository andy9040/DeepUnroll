#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *prev
	struct Node *next;
};
 
struct Node *note;
 
void insert(int key) {
    struct Node *x = (struct Node *)malloc(sizeof(struct Node));
    x->key = key;
	note->next->prev = x;
    x->next = note->next;
    note->next = x;
    x->prev = note;
}
 
struct Node* search(int key) {
    struct Node *x = note->next;
    while(x != note && x->key != key ) {
        x = x-> next;
    }
    return x;
}
 
void deleteNode(struct Node *x) {
    if (x == note) return;
    x->prev->next = x->next;
    x->next->prev = x->prev;
    free(x);
}
 
void deleteFirst() {
    deleteNode(note->next);
}
 
void deleteLast() {
    deleteNode(note->prev);
}
void deleteKey(int key) {
    deleteNode(search(key));
}
 
void print() {
    struct Node *x;
    x = note->next;
    int isf = 0;
    while(1) {
        if (x == note) break;
        if(isf++ > 0) printf(" ");
        printf("%d", x->key);
        x = x->next;
    }
    printf("\n");
}
 
 
int main(void) {
    int key, n;
    char order[20];
    scanf("%d", &n);
	note = (struct Node *)malloc(sizeof(struct Node));
    note->next = note;
    note->prev = note;
    for (int i = 0; i < n; i++) {
        scanf("%s%d",order, &key);
        if(order[0] == 'i') {
            insert(key);
        } 
    	if(com[0] == 'd') {
            if(strlen(order) < 6) {
            	deleateKey();
            }else{
                if( order[6] == 'F') {
                    deleteFirst();
                }
            	if(com[6] == 'L') {
                    deleteLast();
                }
            }
    	}
    }
    print();
    return 0;
}