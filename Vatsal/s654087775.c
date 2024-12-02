#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil;

NodePointer listSearch(int key){
  NodePointer ccc;
  ccc=nil->next;
  while(ccc!=nil && ccc->key!=key){
    ccc=ccc->next;
  }
  return ccc;
}

void init(){
  nil = malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}

void deleteNode(NodePointer t){
  if(t==nil)
    return;
  t->prev->next=t->next;
  t->next->prev=t->prev;
  free(t);
}

void deleteFirst(){
  NodePointer t = nil->next;
  if ( t == nil ) return;
  deleteNode(t);
}

void deleteLast(){
  deleteNode(nil->prev);
}

void delete(int key){
  deleteNode(listSearch(key));
}


void insert(int key){
  NodePointer x;
  x = malloc(sizeof(struct node));
  x->key = key;
  x->next=nil->next;
  nil->next->prev=x;
  nil->next=x;
  x->prev=nil;
}

int main(){
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

  printList();
  return 0;
}

