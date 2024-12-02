#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *next;
    struct node *prev;
};
 
typedef struct node * NodePointer;
NodePointer finditem(int);
void listprint(void);
NodePointer make_1node(int,NodePointer);
void deleteFirst(void);
void deleteLast(void);
void deleteNode(NodePointer);
NodePointer head;
 
int main(void){
    int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);
  init();
  for ( i = 0; i < n; i++ ){
    scanf("%s%d", com, &key);
    if ( com[0] == 'i' ) {insert(key); np++; size++;}
    else if ( com[0] == 'd' ) {
      if (strlen(com) > 6){
    if ( com[6] == 'F' ) deleteFirst();
    else if ( com[6] == 'L' ) deleteLast();
      } else {
    delete(key); nd++;
      }
      size--;
    }
  }
    
  listprint();
  return 0;
}
 
NodePointer finditem(int key){
  NodePointer x;
  x = head->next;
  while(x != head && x->key != key){
    x = x->next;
  }
  return x;
}
 
void insert(int key){
  NodePointer y;
  y = malloc(sizeof(struct node));
  y->key = key;
  y->next = head->next;
  head->next->prev = y;
  head->next = y;
  y->prev = head;
    
}
 
void listprint(){
  NodePointer cur = head->next;
  int isf = 1;
  while(1){
    if ( cur == head ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}
 
void deleteNode(NodePointer t){
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}
  
void deleteFirst(){
  NodePointer t = head->next;
  if ( t == head ) return;
  deleteNode(t);
}
  
void deleteLast(){
  NodePointer t = head->prev;
  if ( t == head ) return;
  deleteNode(t);
}
  
void delete(int key){
  NodePointer k;
  k=finditem(key);
  if(k == head) return;
    
  deleteNode(k);
    
}
void init(){
  head = malloc(sizeof(struct node));
  head->next = head;
  head->prev = head;
}